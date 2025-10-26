#ifndef _Disneyland_improve_H
#define _Disneyland_improve_H


#include <stdint.h>

/*========================
 *  一、核心数据结构
 *========================*/
typedef struct
{
    int y, m, d;
} Date;

typedef struct
{
    Date birth;       // 出生日期
    Date entry;       // 入园日期
    int height;       // 身高(cm)
    int ticket_type;  // 1=单日；2=两日
    bool is_disabled; // 是否残障
} PersonVisit;

typedef struct
{
    int regular_ticket; // 平日票价
    int peak_ticket;    // 高峰票价
} PricePolicy;

/* 公历→农历：返回农历年/月/日与是否闰月 */
typedef struct
{
    int year;
    int month;
    int day;
    int isLeap; // 0=平月, 1=闰月
} LunarDate;

/*========================
 *  二、函数声明
 *========================*/
/* 日期/日历工具 */
static int dayOfWeek(int y, int m, int d); // 0=周日, 1=周一, ..., 6=周六
static int compareDate(Date a, Date b);    // a<b:-1, a==b:0, a>b:1
static int round_up(double x) { return (int)ceil(x); }
bool IsLeapYear(int y);

/* 业务判定（全部用结构体/Date） */
void Judge(int y, int m,int d);
bool IsWeekend(Date d);
bool IsHoliday(Date d);
bool IsSummerHoliday(Date d);
bool IsOpeningDay(Date d);

/* 人群与年龄（结构体接口） */
int GetAge(PersonVisit pv);
bool IsRegularTicket(PersonVisit pv);
bool IsSenior(PersonVisit pv);
bool IsChild(PersonVisit pv);
bool IsInfant(PersonVisit pv);
bool IsTwoDayTicket(PersonVisit pv);
bool IsDiability(PersonVisit pv);

/* 定价（结构体接口） */
int GetTicketPrice(PersonVisit pv, PricePolicy price);

/* 农历内部函数（保留原有实现思路） */
static int lunarYearDays(int y);
static int leapMonth(int y);
static int leapDays(int y);
static int monthDays(int y, int m);
static long daysOffsetFrom19000131(int y, int m, int d);
static LunarDate solarToLunar(int year, int month, int day);

/*========================
 *  八、实现 - 农历算法（原逻辑保留）
 *========================*/
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
    0x0e968, 0x0d520, 0x0daa0, 0x16aa6, 0x056d0, 0x04ae0, 0x0a9d4, 0x0a2d0, 0x0d150, 0x0f252
};

static int lunarYearDays(int y)
{
    uint32_t info = LUNAR_INFO[y - 1900];
    int sum = 348; // 12*29
    for (int i = 0x8000; i > 0x8; i >>= 1)
        sum += (info & i) ? 1 : 0; // 大月+1天

    int leap = info & 0xF;
    if (leap)
        sum += ((info & 0x10000) ? 30 : 29);
    return sum;
}

static int leapMonth(int y)
{
    return LUNAR_INFO[y - 1900] & 0xF;
}

static int leapDays(int y)
{
    int lm = leapMonth(y);
    if (!lm)
        return 0;
    return (LUNAR_INFO[y - 1900] & 0x10000) ? 30 : 29;
}

static int monthDays(int y, int m)
{
    return (LUNAR_INFO[y - 1900] & (0x10000 >> m)) ? 30 : 29;
}

/* 计算从 1900-01-31（农历1900-正月初一）到指定公历日的偏移天数 */
static long daysOffsetFrom19000131(int y, int m, int d)
{
    int a = (14 - m) / 12;
    int yy = y + 4800 - a;
    int mm = m + 12 * a - 3;
    long jdn = d + (153 * mm + 2) / 5 + 365L * yy + yy / 4 - yy / 100 + yy / 400 - 32045;
    long jdn_base = 2415051; // 1900-01-31
    return jdn - jdn_base;
}

static LunarDate solarToLunar(int y, int m, int d)
{
    LunarDate L = {2016, 1, 1, 0};
    long offset = daysOffsetFrom19000131(y, m, d);
    int iYear, daysInYear;

    /* 找到农历年（注：与原实现一致，从2016起步） */
    for (iYear = 2016; iYear <= 2099 && offset >= (daysInYear = lunarYearDays(iYear)); ++iYear)
    {
        offset -= daysInYear;
    }
    L.year = iYear;

    int leap = leapMonth(L.year);
    L.isLeap = 0;

    int iMonth = 1;
    int daysInMonth;

    while (1)
    {
        if (leap && iMonth == (leap + 1) && L.isLeap == 0)
        {
            --iMonth; // 进入闰月
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
            L.isLeap = 0; // 闰月结束
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



#endif	