#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

/* 公历→农历：返回农历年/月/日与是否闰月 */
typedef struct
{
    int year;
    int month;
    int day;
    int isLeap; // 0=平月, 1=闰月
} LunarDate;

/* ---------- 函数声明 ---------- */
bool IsLeapYear(int y);
void Judge(int y, int m, int d);
bool IsWeekend(int enterdate_year, int enterdate_month, int enterdate_day);
bool IsHoliday(int enterdate_year, int enterdate_month, int enterdate_day);
bool IsSummerHoliday(int enterdate_month);
bool IsOpeningDay(int enterdate_year, int enterdate_month, int enterdate_day);
bool IsRegularTicket(int birthdate_year, int birthdate_month, int birthdate_day, int enterdate_year, int enterdate_month, int enterdate_day, int height);
bool IsSenior(int birthdate_year, int birthdate_month, int birthdate_day, int enterdate_year, int enterdate_month, int enterdate_day);
bool IsChild(int height);
bool IsTwoDayTicket(int ticket);
bool IsInfant(int height);
bool IsDiability(int is_diability);
int GetAge(int birthdate_year, int birthdate_month, int birthdate_day, int enterdate_year, int enterdate_month, int enterdate_day);
int GetTicketPrice(int regular_ticket, int peak_day_ticket, bool is_weekend, bool is_holiday, bool is_summer_holiday, bool is_opening_day, bool is_regular_ticket, bool is_senior, bool is_child, bool is_infant, bool is_two_day_ticket, bool is_disability);

/* 农历内部函数 */
static int lunarYearDays(int y);
static int leapMonth(int y);
static int leapDays(int y);
static int monthDays(int y, int m);
static long daysOffsetFrom19000131(int y, int m, int d);
static LunarDate solarToLunar(int year, int month, int day);

/* 工具：星期与取整 */
static int dayOfWeek(int y, int m, int d);
static int round_up(double x) { return (int)ceil(x); }

int main()
{
    int birthdate_year, birthdate_month, birthdate_day;
    int enterdate_year, enterdate_month, enterdate_day;
    int height, ticket;
    int is_diability = 0;
    int regular_ticket = 370;
    int peak_day_ticket = 499;

    printf("Please enter\n");
    printf("Birth date(xxxx xx xx):\n");
    scanf("%d %d %d", &birthdate_year, &birthdate_month, &birthdate_day);

    Judge(birthdate_year, birthdate_month, birthdate_day);

    printf("Height(cm):\n");
    scanf("%d", &height);

    printf("Entry date(xxxx xx xx):\n");
    scanf("%d %d %d", &enterdate_year, &enterdate_month, &enterdate_day);

    Judge(enterdate_year, enterdate_month, enterdate_day);

    printf("Ticket type(1:One-day ticket;2:Two-day ticket):\n");
    scanf("%d", &ticket);

    printf("Are you disabled?(1:Yes;2:No):\n");
    scanf("%d", &is_diability);

    //判断入园日期是否在开幕之前
    if (enterdate_year < 2016 ||
        (enterdate_year == 2016 && enterdate_month < 6) ||
        (enterdate_year == 2016 && enterdate_month == 6 && enterdate_day < 16))
    {
        printf("Please enter the correct date.\n");
        return 0;
    }

    //判断出生日期是否在入园日期之前
    if (enterdate_year < birthdate_year ||
        (enterdate_year == birthdate_year && enterdate_month < birthdate_month) ||
        (enterdate_year == birthdate_year && enterdate_month == birthdate_month && enterdate_day < birthdate_day))
    {
        printf("Please enter the correct date.\n");
        return 0;
    }

    bool is_weekend = IsWeekend(enterdate_year, enterdate_month, enterdate_day);
    bool is_holiday = IsHoliday(enterdate_year, enterdate_month, enterdate_day);
    bool is_summer_holiday = IsSummerHoliday(enterdate_month);
    bool is_opening_day = IsOpeningDay(enterdate_year, enterdate_month, enterdate_day);
    bool is_regular_ticket = IsRegularTicket(birthdate_year, birthdate_month, birthdate_day, enterdate_year, enterdate_month, enterdate_day, height);
    bool is_senior = IsSenior(birthdate_year, birthdate_month, birthdate_day, enterdate_year, enterdate_month, enterdate_day);
    bool is_child = IsChild(height);
    bool is_infant = IsInfant(height);
    bool is_two_day_ticket = IsTwoDayTicket(ticket);
    bool is_disability = IsDiability(is_diability);

    int price = GetTicketPrice(regular_ticket, peak_day_ticket, is_weekend, is_holiday, is_summer_holiday, is_opening_day, is_regular_ticket, is_senior, is_child, is_infant, is_two_day_ticket, is_disability);
    printf("price: %d\n", price);

    return 0;
}


bool IsLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void Judge(int y, int m, int d)
{
    if (m < 1 || m > 12)
    {
        printf("Please enter the correct date.\n");
        exit(0); 
    }

    if (m == 1 ||
        m == 3 ||
        m == 5 ||
        m == 7 ||
        m == 8 ||
        m == 10 ||
        m == 12)
    {
        if (d > 31 || d < 1)
        {
            printf("Please enter the correct date.\n");
            exit(0); 
        }
    }

    if (m == 4 ||
        m == 6 ||
        m == 9 ||
        m == 11)
    {
        if (d > 30 || m < 1)
        {
            printf("Please enter the correct date.\n");
            exit(0); 
        }
    }

    if (IsLeapYear(y))
    {
        if (m == 2)
        {
            if (d > 29 || d < 1)
            {
                printf("Please enter the correct date.\n");
                exit(0); 
            }
        }
    }
    else
    {
        if (m == 2)
        {
            if (d > 28 || d < 1)
            {
                printf("Please enter the correct date.\n");
                exit(0); 
            }
        }
    }
}

/* ---------- 周末（稳定算法） ---------- */
/* Sakamoto：0=周日,1=周一,...,6=周六 */
static int dayOfWeek(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3)
        y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}
bool IsWeekend(int y, int m, int d)
{
    int w = dayOfWeek(y, m, d);
    return (w == 0 || w == 6);
}

// 是否是假期
bool IsHoliday(int enterdate_year, 
               int enterdate_month, 
               int enterdate_day)
{
    // 元旦
    if (enterdate_month == 1 && 
        enterdate_day == 1)
        return true;

    // 清明节
    if (enterdate_month == 4 && 
        (enterdate_day >= 4 && 
         enterdate_day <= 6))
        return true; // 清明浮动范围
    // 劳动节
    if (enterdate_month == 5 && 
        (enterdate_day >= 1 && 
         enterdate_day <= 5))
    return true;
    // 国庆节
    if (enterdate_month == 10 && (enterdate_day >= 1 && enterdate_day <= 7))
        return true;

    // 支持 1900-01-31 起至 2099 年
    if (enterdate_year < 1900 || enterdate_year > 2099)
    {
        return false;
    }

    LunarDate L = solarToLunar(enterdate_year, enterdate_month, enterdate_day);

    // 春节假期周：农历 1-1到1-7（不区分闰/平）
    if (L.month == 1 && L.day >= 1 && L.day <= 7)
        return true;
    // 特别处理除夕（即腊月最后一天）
    else if (L.month == 12 && L.day == monthDays(L.year, 12))
    {
        return true;
    }
    // 端午：农历 5-5（如遇闰五月，通常节日在“平五月”，这里采用常用处理：仅平月判断）
    if (!L.isLeap && L.month == 5 && L.day == 5)
        return true;

    // 中秋：农历 8-15（同理，仅平月判断）
    if (!L.isLeap && L.month == 8 && L.day == 15)
        return true;

    return false;
}

// 是否是暑假
bool IsSummerHoliday(int enterdate_month)
{
    if (enterdate_month == 7 || 
        enterdate_month == 8)
        return true;
    else
        return false;
}


/*
* 是否是盛大开幕期*/ 
bool IsOpeningDay(int enterdate_year, int enterdate_month, int enterdate_day)
{
    if (enterdate_year == 2016 && enterdate_month == 6 && (enterdate_day <= 30 && enterdate_day >= 16))
    {
        return true;
    }

    else
    {
        return false;
    }
}

// 年龄
int GetAge(int birthdate_year, 
            int birthdate_month, 
            int birthdate_day, 
            int enterdate_year, 
            int enterdate_month, 
            int enterdate_day)
{
    int age = enterdate_year - birthdate_year;
    if (enterdate_month < birthdate_month || 
        (enterdate_month == birthdate_month && 
         enterdate_day < birthdate_day))
    {
        age--;
    }
    return age;
}

// 是否是常规门票
bool IsRegularTicket(int birthdate_year, 
                    int birthdate_month, 
                    int birthdate_day, 
                    int enterdate_year, 
                    int enterdate_month, 
                    int enterdate_day, 
                    int height)
{
    if (GetAge(birthdate_year, 
                birthdate_month, 
                birthdate_day, 
                enterdate_year, 
                enterdate_month, 
                enterdate_day) < 65 && 
        height >= 140)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 是否是老年人
bool IsSenior(int birthdate_year, int birthdate_month, int birthdate_day, int enterdate_year, int enterdate_month, int enterdate_day)
{
    if (GetAge(birthdate_year, birthdate_month, birthdate_day, enterdate_year, enterdate_month, enterdate_day) >= 65)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 是否是儿童
bool IsChild(int height)
{
    if (height <= 140 && height > 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 是否是婴幼儿
bool IsInfant(int height)
{
    if (height <= 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 是否是两日联票
bool IsTwoDayTicket(int ticket)
{
    if (ticket == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 是否是残障人士
bool IsDiability(int is_diability)
{
    if (is_diability == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 票价
int GetTicketPrice(int regular_ticket, int peak_day_ticket, bool is_weekend, bool is_holiday, bool is_summer_holiday, bool is_opening_day, bool is_regular_ticket, bool is_senior, bool is_child, bool is_infant, bool is_two_day_ticket, bool is_disability)
{
    /* 1) 婴幼儿免费（直接返回） */
    if (is_infant)
        return 0;

    /* 2) 先确定当日基础票价（高峰/平日） */
    int base = (is_weekend || is_holiday || is_summer_holiday || is_opening_day)
                   ? peak_day_ticket
                   : regular_ticket;

    /* 3) 先应用人群折扣（若符合：老年/儿童/残障 -> 75折） */
    double price = (double)base;
    if (is_senior || is_child || is_disability)
    {
        price *= 0.75;
    }

    /* 4) 再看是否两日联票（在折后基础上 ×2×0.95） */
    if (is_two_day_ticket)
    {
        price = price * 2.0 * 0.95;
    }

    /* 5) 常规票（身高≥140 且 <65 岁）只是一个类别标识；
          若既不享受人群折扣也不是两日联票，则相当于原价。这里无需额外处理。 */

    /* 6) 统一向上取整 */
    return round_up(price);
}

/* 农历信息表（每年 16bit：0x? 表示每月大小月，低 4bit 表示闰月，闰月大小在高位） */
static const uint32_t LUNAR_INFO[] = {

    /* 1900-1909 */
    0x04bd8, 0x04ae0, 0x0a570, 0x054d5, 0x0d260, 0x0d950, 0x16554, 0x056a0, 0x09ad0, 0x055d2,
    /* 1910-1919 */
    0x04ae0, 0x0a5b6, 0x0a4d0, 0x0d250, 0x1d255, 0x0b540, 0x0d6a0, 0x0ada2, 0x095b0, 0x14977,
    /* 1920-1929 */
    0x04970, 0x0a4b0, 0x0b4b5, 0x06a50, 0x06d40, 0x1ab54, 0x02b60, 0x09570, 0x052f2, 0x04970,
    /* 1930-1939 */
    0x06566, 0x0d4a0, 0x0ea50, 0x06e95, 0x05ad0, 0x02b60, 0x186e3, 0x092e0, 0x1c8d7, 0x0c950,
    /* 1940-1949 */
    0x0d4a0, 0x1d8a6, 0x0b550, 0x056a0, 0x1a5b4, 0x025d0, 0x092d0, 0x0d2b2, 0x0a950, 0x0b557,
    /* 1950-1959 */
    0x06ca0, 0x0b550, 0x15355, 0x04da0, 0x0a5b0, 0x14573, 0x052b0, 0x0a9a8, 0x0e950, 0x06aa0,
    /* 1960-1969 */
    0x0aea6, 0x0ab50, 0x04b60, 0x0aae4, 0x0a570, 0x05260, 0x0f263, 0x0d950, 0x05b57, 0x056a0,
    /* 1970-1979 */
    0x096d0, 0x04dd5, 0x04ad0, 0x0a4d0, 0x0d4d4, 0x0d250, 0x0d558, 0x0b540, 0x0b6a0, 0x195a6,
    /* 1980-1989 */
    0x095b0, 0x049b0, 0x0a974, 0x0a4b0, 0x0b27a, 0x06a50, 0x06d40, 0x0af46, 0x0ab60, 0x09570,
    /* 1990-1999 */
    0x04af5, 0x04970, 0x064b0, 0x074a3, 0x0ea50, 0x06b58, 0x05ac0, 0x0ab60, 0x096d5, 0x092e0,
    /* 2000-2009 */
    0x0c960, 0x0d954, 0x0d4a0, 0x0da50, 0x07552, 0x056a0, 0x0abb7, 0x025d0, 0x092d0, 0x0cab5,
    /* 2010-2019 */
    0x0a950, 0x0b4a0, 0x0baa4, 0x0ad50, 0x055d9, 0x04ba0, 0x0a5b0, 0x15176, 0x052b0, 0x0a930,
    /* 2020-2029 */
    0x07954, 0x06aa0, 0x0ad50, 0x05b52, 0x04b60, 0x0a6e6, 0x0a4e0, 0x0d260, 0x0ea65, 0x0d530,
    /* 2030-2039 */
    0x05aa0, 0x076a3, 0x096d0, 0x04bd7, 0x04ad0, 0x0a4d0, 0x1d0b6, 0x0d250, 0x0d520, 0x0dd45,
    /* 2040-2049 */
    0x0b5a0, 0x056d0, 0x055b2, 0x049b0, 0x0a577, 0x0a4b0, 0x0aa50, 0x1b255, 0x06d20, 0x0ada0,
    /* 2050-2059 */
    0x14b63, 0x09370, 0x049f8, 0x04970, 0x064b0, 0x168a6, 0x0ea50, 0x06b20, 0x1a6c4, 0x0aae0,
    /* 2060-2069 */
    0x0a2e0, 0x0d2e3, 0x0c960, 0x0d557, 0x0d4a0, 0x0da50, 0x05d55, 0x056a0, 0x0a6d0, 0x055d4,
    /* 2070-2079 */
    0x052d0, 0x0a9b8, 0x0a950, 0x0b4a0, 0x0b6a6, 0x0ad50, 0x055a0, 0x0aba4, 0x0a5b0, 0x052b0,
    /* 2080-2089 */
    0x0b273, 0x06930, 0x07337, 0x06aa0, 0x0ad50, 0x14b55, 0x04b60, 0x0a570, 0x054e4, 0x0d160,
    /* 2090-2099 */
    0x0e968, 0x0d520, 0x0daa0, 0x16aa6, 0x056d0, 0x04ae0, 0x0a9d4, 0x0a2d0, 0x0d150, 0x0f252};

/* 计算某农历年的总天数 */
static int lunarYearDays(int y)
{
    uint32_t info = LUNAR_INFO[y - 1900];
    int sum = 348; // 12*29
    for (int i = 0x8000; i > 0x8; i >>= 1)
    {
        sum += (info & i) ? 1 : 0; // 大月+1天
    }
    // 闰月
    int leap = info & 0xF;
    if (leap)
        sum += ((info & 0x10000) ? 30 : 29);
    return sum;
}

/* 指定年闰月：0表示无闰月，1-12 表示闰月月份 */
static int leapMonth(int y)
{
    return LUNAR_INFO[y - 1900] & 0xF;
}

/* 指定年闰月的天数（0/29/30） */
static int leapDays(int y)
{
    int lm = leapMonth(y);
    if (!lm)
        return 0;
    return (LUNAR_INFO[y - 1900] & 0x10000) ? 30 : 29;
}

/* 指定年农历某月天数（29/30） */
static int monthDays(int y, int m)
{
    return (LUNAR_INFO[y - 1900] & (0x10000 >> m)) ? 30 : 29;
}

/* 计算从 1900-01-31（农历1900-正月初一）到指定公历日的偏移天数 */
static long daysOffsetFrom19000131(int y, int m, int d)
{
    // 公历的儒略日近似（适用于此范围即可）
    int a = (14 - m) / 12;
    int yy = y + 4800 - a;
    int mm = m + 12 * a - 3;
    long jdn = d + (153 * mm + 2) / 5 + 365L * yy + yy / 4 - yy / 100 + yy / 400 - 32045;
    // 1900-01-31 的 JDN
    long jdn_base = 2415051; // 1900-01-31
    return jdn - jdn_base;
}

static LunarDate solarToLunar(int y, int m, int d)
{
    LunarDate L = {2016, 1, 1, 0};
    long offset = daysOffsetFrom19000131(y, m, d);
    int iYear, daysInYear;
    // 找到农历年
    for (iYear = 2016; iYear <= 2099 && offset >= (daysInYear = lunarYearDays(iYear)); ++iYear)
    {
        offset -= daysInYear;
    }
    L.year = iYear;

    // 当年闰月
    int leap = leapMonth(L.year);
    L.isLeap = 0;

    // 月份推进1
    int iMonth = 1;
    int daysInMonth;
    while (1)
    {
        if (leap && iMonth == (leap + 1) && L.isLeap == 0)
        {
            // 进入闰月
            --iMonth; // 调回到闰月
            L.isLeap = 1;
            daysInMonth = leapDays(L.year);
        }
        else
        {
            daysInMonth = monthDays(L.year, iMonth);
        }

        if (offset < daysInMonth)
            break;

        offset -= daysInMonth;
        if (L.isLeap && iMonth == leap)
        {
            // 闰月结束，转回平月
            L.isLeap = 0;
        }
        else
        {
            iMonth++;
        }
    }

    L.month = iMonth;
    L.day = (int)offset + 1;
    return L;
}
