#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include "Disneyland_improve.h"

/*========================
 *  三、主程序
 *========================*/
int main(void)
{
    PersonVisit info = {0};
    PricePolicy price = {.regular_ticket = 370, .peak_ticket = 499};

    printf("Please enter\n");

    printf("Birth date (yyyy mm dd):\n");
    scanf("%d %d %d", &info.birth.y, &info.birth.m, &info.birth.d);

    Judge(info.birth.y,info.birth.m, info.birth.d);

    printf("Height (cm):\n");
    scanf("%d", &info.height);

    printf("Entry date (yyyy mm dd):\n");
    scanf("%d %d %d", &info.entry.y, &info.entry.m, &info.entry.d);

    Judge(info.entry.y,info.entry.m, info.entry.d);

    /* 基本校验：开园时间、出生必须早于入园 */
    const Date SHDL_OPEN = {2016, 6, 16};
    if (compareDate(info.entry, SHDL_OPEN) < 0)
    {
        printf("Please enter the correct date.\n");
        return 0;
    }
    if (compareDate(info.birth, info.entry) >= 0)
    {
        printf("Please enter the correct date.\n");
        return 0;
    }

    printf("Ticket type (1: One-day; 2: Two-day):\n");
    scanf("%d", &info.ticket_type);

    printf("Are you disabled? (1:Yes; 2:No):\n");
    int disabled_input = 2;
    scanf("%d", &disabled_input);
    info.is_disabled = (disabled_input == 1);

    int total = GetTicketPrice(info, price);
    printf("price: %d\n", total);
    return 0;
}

/*========================
 *  四、实现 - 日期/日历工具
 *========================*/
/* Sakamoto 算法：0=周日,1=周一,...,6=周六 */
static int dayOfWeek(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3)
        y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

static int compareDate(Date a, Date b)
{
    if (a.y != b.y)
        return (a.y < b.y) ? -1 : 1;
    if (a.m != b.m)
        return (a.m < b.m) ? -1 : 1;
    if (a.d != b.d)
        return (a.d < b.d) ? -1 : 1;
    return 0;
}

/*========================
 *  五、实现 - 业务判定
 *========================*/

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

bool IsWeekend(Date d)
{
    int w = dayOfWeek(d.y, d.m, d.d);
    return (w == 0 || w == 6);
}

/* 固定假期 + 农历部分（春节周/除夕/端午/中秋） */
bool IsHoliday(Date d)
{
    /* 固定阳历节假日 */
    if (d.m == 1 && d.d == 1)
        return true; // 元旦
    if (d.m == 4 && (d.d >= 4 && d.d <= 6))
        return true; // 清明(浮动范围)
    if (d.m == 5 && (d.d >= 1 && d.d <= 5))
        return true; // 劳动节
    if (d.m == 10 && (d.d >= 1 && d.d <= 7))
        return true; // 国庆节

    /* 农历节假日（支持 1900-2099） */
    if (d.y < 1900 || d.y > 2099)
        return false; // 超范围：保守为非假期

    LunarDate L = solarToLunar(d.y, d.m, d.d);

    /* 春节假期周：农历 1-1 到 1-7 */
    if (L.month == 1 && L.day >= 1 && L.day <= 7)
        return true;

    /* 除夕：农历腊月最后一天 */
    if (L.month == 12 && L.day == monthDays(L.year, 12))
        return true;

    /* 端午：农历5-5（仅平月判断） */
    if (!L.isLeap && L.month == 5 && L.day == 5)
        return true;

    /* 中秋：农历8-15（仅平月判断） */
    if (!L.isLeap && L.month == 8 && L.day == 15)
        return true;

    return false;
}

/* 暑期（按月） */
bool IsSummerHoliday(Date d)
{
    return (d.m == 7 || d.m == 8);
}

/* 盛大开幕期：2016-06-16 ~ 2016-06-30 */
bool IsOpeningDay(Date d)
{
    if (d.y == 2016 && d.m == 6 && d.d >= 16 && d.d <= 30)
        return true;
    return false;
}

/*========================
 *  六、实现 - 人群与年龄
 *========================*/
int GetAge(PersonVisit pv)
{
    int age = pv.entry.y - pv.birth.y;
    if (pv.entry.m < pv.birth.m || (pv.entry.m == pv.birth.m && pv.entry.d < pv.birth.d))
        age--;
    return age;
}

bool IsSenior(PersonVisit pv) { return GetAge(pv) >= 65; }
bool IsInfant(PersonVisit pv) { return pv.height <= 100; }
bool IsChild(PersonVisit pv) { return pv.height > 100 && pv.height <= 140; }
bool IsRegularTicket(PersonVisit pv) { return pv.height >= 140 && GetAge(pv) < 65; }
bool IsTwoDayTicket(PersonVisit pv) { return pv.ticket_type == 2; }
bool IsDiability(PersonVisit pv) { return pv.is_disabled; }

/*========================
 *  七、实现 - 定价
 *========================*/
int GetTicketPrice(PersonVisit pv, PricePolicy price)
{
    /* 1) 婴幼儿免费 */
    if (IsInfant(pv))
        return 0;

    /* 2) 基础票价（高峰/平日） */
    bool is_weekend = IsWeekend(pv.entry);
    bool is_holiday = IsHoliday(pv.entry);
    bool is_summer = IsSummerHoliday(pv.entry);
    bool is_opening = IsOpeningDay(pv.entry);

    int base = (is_weekend ||
                is_holiday ||
                is_summer ||
                is_opening)
                   ? price.peak_ticket
                   : price.regular_ticket;

    /* 3) 人群折扣（老年/儿童/残障 -> 75折） */
    double total = (double)base;
    if (IsSenior(pv) || IsChild(pv) || IsDiability(pv))
        total *= 0.75;

    /* 4) 两日联票：在折后基础上 ×2×0.95 */
    if (IsTwoDayTicket(pv))
        total = total * 2.0 * 0.95;

    /* 5) 常规票只是类别标识，无额外处理 */

    /* 6) 统一向上取整 */
    return round_up(total);
}

