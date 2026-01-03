#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "ciallo.h"
#include <windows.h>

using namespace std;

// #define DEBUG
typedef int ElemType;

typedef struct
{
    // 身份证号
    string id;
    // 姓名
    string name;
    // 入住时间
    string check_in_time;
    // 离开时间
    string check_out_time;
    // 房间编号
    string room_number;
    // 总花费（初始为0）
    ElemType total_cost;
} Guest;

typedef struct
{
    // 房间编号
    string room_number;
    // 房间类型
    string room_type;
    // 房间价格
    ElemType room_price;
    // 房间状态（0——无人，1——有人）
    ElemType room_status;
} Room;

struct guest_node
{
    Guest guest;
    guest_node *next;
};

struct room_node
{
    Room room;
    room_node *next;
};

//------------------------------------------------可视化菜单-------------------------------------------------------
// 初始化菜单
void ShowMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  欢迎来到酒店管理系统  **********" << endl;
    cout << "**********  请选择操作对象     *************" << endl;
    cout << "**********  1.客人信息    ******************" << endl;
    cout << "**********  2.房间信息    ******************" << endl;
    cout << "**********  0.退出系统    ******************" << endl;
    cout << "********************************************" << endl;
}

// 客人信息操作菜单
void ShowGuestMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  1.添加客人信息    **************" << endl;
    cout << "**********  2.删除客人信息    **************" << endl;
    cout << "**********  3.修改客人信息    **************" << endl;
    cout << "**********  4.查询客人信息    **************" << endl;
    cout << "**********  5.显示所有客人信息    **********" << endl;
    cout << "**********  6.返回上级菜单    **************" << endl;
    cout << "********************************************" << endl;
}

// 房间信息操作菜单
void ShowRoomMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  1.添加房间信息    **************" << endl;
    cout << "**********  2.修改房间信息    **************" << endl;
    cout << "**********  3.查询房间信息    **************" << endl;
    cout << "**********  4.返回上级菜单    **************" << endl;
    cout << "********************************************" << endl;
}

// 查询客房操作菜单
void ShowQueryRoomMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  请选择查询内容    **************" << endl;
    cout << "**********  1.房间类型       **************" << endl;
    cout << "**********  2.房间价格区间   **************" << endl;
    cout << "**********  3.返回上级菜单    **************" << endl;
    cout << "********************************************" << endl;
}

// 查询客人操作菜单
void ShowQueryGuestMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  请选择查询内容    **************" << endl;
    cout << "**********  1.身份证号       ***************" << endl;
    cout << "**********  2.客人姓名       ***************" << endl;
    cout << "**********  3.返回上级菜单    **************" << endl;
    cout << "********************************************" << endl;
}
// 修改客人信息操作菜单
void ShowModifyGuestMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  请选择修改内容    **************" << endl;
    cout << "**********  1.修改客人姓名    **************" << endl;
    cout << "**********  2.修改入住时间    **************" << endl;
    cout << "**********  3.修改离开时间    **************" << endl;
    cout << "**********  4.修改房间编号    **************" << endl;
    cout << "**********  5.返回上级菜单    **************" << endl;
    cout << "********************************************" << endl;
}

// 修改客房信息操作菜单
void ShowModifyRoomMenu()
{
    cout << "********************************************" << endl;
    cout << "**********  请选择修改内容    **************" << endl;
    cout << "**********  1.修改房间类型    **************" << endl;
    cout << "**********  2.修改房间价格    **************" << endl;
    cout << "**********  3.返回上级菜单    **************" << endl;
    cout << "********************************************" << endl;
}
//------------------------------------------------文件操作-------------------------------------------------------
// 从文件读取客人数据
/**
 * @brief 从文件读取客人数据到链表
 * @param head 客人链表头结点指针
 * @param filename 文件名
 * @return 0表示成功，-1表示文件不存在，-2表示文件读取失败
 */
int LoadGuestsFromFile(guest_node *head, const string &filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "LoadGuestsFromFile：未找到客人文件，已创建空链表。" << endl;
        return -1;
    }

    guest_node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    Guest g;
    while (fin >> g.id >> g.name >> g.check_in_time >> g.check_out_time >> g.room_number >> g.total_cost)
    {
        guest_node *node = new guest_node;
        node->guest = g;
        node->next = nullptr;
        p->next = node;
        p = p->next;
    }

    fin.close();
    return 0;
}

// 从文件读取客房数据
int LoadRoomsFromFile(room_node *head, const string &filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "LoadRoomsFromFile：未找到客房文件，已创建空链表。" << endl;
        return -1;
    }

    room_node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    Room r;
    while (fin >> r.room_number >> r.room_type >> r.room_price >> r.room_status)
    {
        room_node *node = new room_node;
        node->room = r;
        node->next = nullptr;
        p->next = node;
        p = p->next;
    }

    fin.close();
    return 0;
}

// 保存客人数据到文件
void SaveGuests(guest_node *head)
{
    ofstream fout("guests.txt");
    for (guest_node *p = head->next; p; p = p->next)
        fout << left
             << setw(20) << p->guest.id
             << setw(16) << p->guest.name
             << setw(14) << p->guest.check_in_time
             << setw(14) << p->guest.check_out_time
             << setw(12) << p->guest.room_number
             << setw(12) << p->guest.total_cost
             << endl;
}

// 保存客房数据到文件
void SaveRooms(room_node *head)
{
    ofstream fout("room.txt");
    for (room_node *p = head->next; p; p = p->next)
        fout << left
             << setw(15) << p->room.room_number
             << setw(20) << p->room.room_type
             << setw(15) << p->room.room_price
             << setw(10) << p->room.room_status
             << endl;
}

//------------------------------------------------工具函数-------------------------------------------------------
// 检查是否是闰年
bool IsLeapYear(ElemType year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 是否是合法日期
bool IsValidDate(ElemType year, ElemType month, ElemType day)
{
    if (year < 1900 || year > 2100)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool is_leap = IsLeapYear(year);
    if (is_leap)
        days_in_month[1] = 29;
    if (day < 1 || day > days_in_month[month - 1])
        return false;
    return true;
}

// 计算某年某月天数
int DaysInMonth(int year, int month)
{
    static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year))
        return 29;
    return days[month - 1];
}

// 检查是否是合法身份证号
bool IsValidID(const string &id)
{
    // 长度是否为18
    if (id.length() != 18)
        return false;

    // 前十七位是否是数字
    for (size_t i = 0; i < id.length() - 1; i++)
    {
        if (!isdigit(id[i]))
            return false;
    }

    // 最后一位是否是数字或X
    if (!isdigit(id[17]) && id[17] != 'X')
        return false;

    // 出生年月日校验
    int year = stoi(id.substr(6, 4));
    int month = stoi(id.substr(10, 2));
    int day = stoi(id.substr(12, 2));

    bool is_valid_date = IsValidDate(year, month, day);
    if (!is_valid_date)
        return false;

    // 校验码计算
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3,
                      7, 9, 10, 5, 8, 4, 2};
    char checkMap[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int sum = 0;
    for (int i = 0; i < 17; ++i)
    {
        sum += (id[i] - '0') * weight[i];
    }

    char expected = checkMap[sum % 11];
    return id[17] == expected;
}

// 检查是否是合法日期字符串
bool IsValidDateString(const string &date_str)
{
    if (date_str.length() != 10 ||
        date_str[4] != '-' ||
        date_str[7] != '-')
        return false;

    for (int i : {0, 1, 2, 3, 5, 6, 8, 9})
        if (!isdigit(date_str[i]))
            return false;

    int year = stoi(date_str.substr(0, 4));
    int month = stoi(date_str.substr(5, 2));
    int day = stoi(date_str.substr(8, 2));
    return IsValidDate(year, month, day);
}

// 检查是否是新房号
bool IsNewRoom(room_node *head, const string &room_number)
{
    room_node *p = head->next;
    while (p != nullptr)
    {
        if (p->room.room_number == room_number)
        {
            return false;
        }
        p = p->next;
    }
    return true;
}

// 检查是否是新客人
bool IsNewGuest(guest_node *head, const string &id)
{
    guest_node *p = head->next;
    while (p != nullptr)
    {
        if (p->guest.id == id)
        {
            return false;
        }
        p = p->next;
    }
    return true;
}

// 检验入住时间和离开时间是否合法
bool CheckInAndOutTime(const string &check_in_time, const string &check_out_time)
{
    // 检查入住时间是否小于离开时间
    int in_year = stoi(check_in_time.substr(0, 4));
    int in_month = stoi(check_in_time.substr(5, 2));
    int in_day = stoi(check_in_time.substr(8, 2));

    int out_year = stoi(check_out_time.substr(0, 4));
    int out_month = stoi(check_out_time.substr(5, 2));
    int out_day = stoi(check_out_time.substr(8, 2));

    if (in_year > out_year)
        return false;
    if (in_year == out_year && in_month > out_month)
        return false;
    if (in_year == out_year && in_month == out_month && in_day >= out_day)
        return false;
    return true;
}

// 计算距1900-01-01天数
int DateToDays(int year, int month, int day)
{
    int total = 0;

    // 1. 计算整年的天数
    for (int y = 1900; y < year; y++)
    {
        total += IsLeapYear(y) ? 366 : 365;
    }

    // 2. 计算当年整月的天数
    for (int m = 1; m < month; m++)
    {
        total += DaysInMonth(year, m);
    }

    // 3. 加上当月天数
    total += day;

    return total;
}

// 计算总费用
ElemType CalculateTotalCost(room_node *rhead, const string &room_number, guest_node *p)
{
    // 1. 找房间，拿到价格
    room_node *q = rhead->next;
    int price = 0;
    while (q != nullptr)
    {
        if (q->room.room_number == room_number)
        {
            price = q->room.room_price;
            break;
        }
        q = q->next;
    }

    if (price == 0)
        return 0; // 房间不存在或价格异常

    // 2. 解析入住时间
    int in_year = stoi(p->guest.check_in_time.substr(0, 4));
    int in_month = stoi(p->guest.check_in_time.substr(5, 2));
    int in_day = stoi(p->guest.check_in_time.substr(8, 2));

    int out_year = stoi(p->guest.check_out_time.substr(0, 4));
    int out_month = stoi(p->guest.check_out_time.substr(5, 2));
    int out_day = stoi(p->guest.check_out_time.substr(8, 2));

    // 3. 转换为总天数
    int in_days = DateToDays(in_year, in_month, in_day);
    int out_days = DateToDays(out_year, out_month, out_day);

    // 4. 计算入住天数（至少 1 天）
    int stay_days = out_days - in_days;
    if (stay_days <= 0)
        stay_days = 1;

    // 5. 总费用
    ElemType total_cost = stay_days * price;
    return total_cost;
}

// 输出客人信息表头
void PrintGuestHeader()
{
    cout << left
         << setw(26) << "身份证号"
         << setw(12) << "姓名"
         << setw(17) << "入住时间"
         << setw(16) << "离开时间"
         << setw(18) << "房间编号"
         << setw(12) << "总费用"
         << endl;

    cout << string(86, '-') << endl;
}

// 输出查询客人信息
void ShowGuestInfo(guest_node *p)
{
    if (p == nullptr)
    {
        cout << "客人信息不存在。" << endl;
        return;
    }

    cout << left
         << setw(22) << p->guest.id
         << setw(12) << p->guest.name
         << setw(14) << p->guest.check_in_time
         << setw(14) << p->guest.check_out_time
         << setw(12) << p->guest.room_number
         << setw(12) << p->guest.total_cost
         << endl;
}

// 输出客房信息表头
void PrintRoomHeader()
{
    cout << left
         << setw(16) << "房间编号"
         << setw(16) << "房间类型"
         << setw(16) << "房间价格"
         << setw(10) << "房间状态"
         << endl;

    cout << string(52, '-') << endl;
}

// 输出客房信息
void ShowRoomInfo(room_node *p)
{
    // 去除房间类型的尾部空格
    string type = p->room.room_type;
    size_t end_pos = type.find_last_not_of(' ');
    if (end_pos != string::npos)
    {
        type = type.substr(0, end_pos + 1);
    }

    cout << left
         << setw(12) << p->room.room_number
         << setw(16) << type
         << setw(14) << p->room.room_price
         << setw(10) << (p->room.room_status == 0 ? "空闲" : "已入住")
         << endl;
}

//------------------------------------------------客人操作-------------------------------------------------------
// 查询客人信息，包含计算总花费
void FindGuest(guest_node *ghead, room_node *rhead)
{
    ShowQueryGuestMenu();
    int choice;
    cout << "请输入查询内容：";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        string id;
        cout << "请输入要查询的身份证号：";
        cin >> id;
        guest_node *p = ghead->next;
        ElemType total_cost = 0;
        while (p != nullptr)
        {
            if (p->guest.id == id)
            {
                string room_number = p->guest.room_number;
                total_cost = CalculateTotalCost(rhead, room_number, p);
                p->guest.total_cost = total_cost;
                ShowGuestInfo(p);
                return; // 找到后立即返回
            }

            p = p->next;
        }
        cout << "未找到该身份证号的客人信息。" << endl;
        break;
    }
    case 2:
    {
        string name;
        cout << "请输入要查询的姓名：";
        cin >> name;
        guest_node *p = ghead->next;
        ElemType total_cost = 0;
        while (p != nullptr)
        {
            // 去除客人姓名的尾部空格后再比较
            string guest_name = p->guest.name;
            size_t end_pos = guest_name.find_last_not_of(' ');
            if (end_pos != string::npos)
            {
                guest_name = guest_name.substr(0, end_pos + 1);
            }

            if (guest_name == name)
            {
                string room_number = p->guest.room_number;
                total_cost = CalculateTotalCost(rhead, room_number, p);
                p->guest.total_cost = total_cost;
                ShowGuestInfo(p);
                return; // 找到后立即返回
            }

            p = p->next;
        }
        cout << "未找到该姓名的客人信息。" << endl;
        break;
    }
    case 3:
    {
        return;
    }
    default:
    {
        cout << "输入错误，请重新输入！" << endl;
        break;
    }
    }
}

// 显示所有客人信息，包含计算总花费
void ShowAllGuests(guest_node *ghead, room_node *rhead)
{
    guest_node *p = ghead->next;
    if (p == nullptr)
    {
        cout << "当前暂无客人信息。" << endl;
        return;
    }
    PrintGuestHeader();
    while (p != nullptr)
    {
        string room_number = p->guest.room_number;
        ElemType total_cost = CalculateTotalCost(rhead, room_number, p);
        p->guest.total_cost = total_cost;
        ShowGuestInfo(p);
        p = p->next;
    }
}

// 新增客人信息，用身份证号验证，如果不存在，逐项添加，花费=0，状态=1
void AddGuest(guest_node *ghead, room_node *rhead)
{
    Guest new_guest;
    string id;

    // 身份证号输入循环
    while (true)
    {
        cout << "请输入客人身份证号：";
        cin >> id;
        if (id == "0")
            return; // 用户取消

        else if (!IsValidID(id))
        {
            cout << "身份证号无效，请重新输入！" << endl;
            continue;
        }
        else if (!IsNewGuest(ghead, id))
        {
            cout << "客人已存在，请重新输入！" << endl;
            continue;
        }

        else
        {
            new_guest.id = id;
            break; // 身份证号合法且不存在
        }
    }

    // 姓名输入
    cout << "请输入客人姓名：";
    cin >> new_guest.name;

    // 入住时间输入验证
    while (true)
    {
        cout << "请输入入住时间(YYYY-MM-DD)：";
        cin >> new_guest.check_in_time;
        if (new_guest.check_in_time == "0")
            return;
        if (!IsValidDateString(new_guest.check_in_time))
        {
            cout << "入住时间格式错误，请重新输入！" << endl;
            continue;
        }
        break;
    }

    // 离开时间输入验证
    while (true)
    {
        cout << "请输入离开时间(YYYY-MM-DD)：";
        cin >> new_guest.check_out_time;
        if (new_guest.check_out_time == "0")
            return;
        if (!IsValidDateString(new_guest.check_out_time))
        {
            cout << "离开时间格式错误，请重新输入！" << endl;
            continue;
        }
        if (!CheckInAndOutTime(new_guest.check_in_time, new_guest.check_out_time))
        {
            cout << "离开时间必须晚于入住时间，请重新输入！" << endl;
            continue;
        }
        break;
    }

    // 房间编号输入验证
    string room_number;
    while (true)
    {
        cout << "请输入房间编号：";
        cin >> room_number;
        if (room_number == "0")
            return;

        if (IsNewRoom(rhead, room_number))
        {
            cout << "房间编号不存在，请重新输入！" << endl;
            continue;
        }

        // 检查房间状态
        room_node *p = rhead->next;
        bool can_use = false;
        while (p != nullptr)
        {
            if (p->room.room_number == room_number)
            {
                if (p->room.room_status == 1)
                {
                    cout << "该房间已有客人入住，请重新选择。" << endl;
                    can_use = false;
                    break;
                }
                else
                {
                    p->room.room_status = 1; // 标记为有人
                    can_use = true;
                    break;
                }
            }
            p = p->next;
        }
        if (can_use)
            break;
    }
    new_guest.room_number = room_number;

    // 总费用初始化
    new_guest.total_cost = 0;

    // 添加到客人链表末尾
    guest_node *p = ghead;
    while (p->next != nullptr)
        p = p->next;

    guest_node *new_node = new guest_node;
    new_node->guest = new_guest;
    new_node->next = nullptr;
    p->next = new_node;

    cout << "新客人添加成功！" << endl;
}

// 修改客人信息，用身份证号验证
void ModifyGuest(guest_node *ghead, room_node *rhead)
{
    string id;
    guest_node *p = ghead->next;
    int choice;

    // 输入要修改的客人身份证号
    while (true)
    {
        cout << "请输入要修改的客人身份证号：";
        cin >> id;
        if (id == "0")
            return; // 用户取消操作

        if (IsNewGuest(ghead, id))
        {
            cout << "未找到该客人信息，请重新输入！" << endl;
            continue;
        }
        break; // 找到该客人
    }
    cout << "已找到该客人！" << endl;

    // 查找该客人
    while (p != nullptr)
    {
        if (p->guest.id == id)
        {
            string old_in = p->guest.check_in_time;
            string old_out = p->guest.check_out_time;

            ShowModifyGuestMenu(); // 显示修改菜单
            while (true)
            {
                cout << "请输入要修改的选项：";
                cin >> choice;
                if (choice == 0)
                    return; // 取消修改操作

                switch (choice)
                {
                case 1:
                { // 修改客人姓名
                    cout << "请输入新的客人姓名：";
                    cin >> p->guest.name;
                    break;
                }

                case 2:
                { // 修改入住时间
                    while (true)
                    {
                        cout << "请输入新的入住时间（格式：YYYY-MM-DD）：";
                        cin >> p->guest.check_in_time;
                        if (p->guest.check_in_time == "0")
                            return; // 取消操作

                        if (!IsValidDateString(p->guest.check_in_time))
                        {
                            cout << "入住时间格式错误，请重新输入！" << endl;
                            continue;
                        }
                        break;
                    }
                    break;
                }

                case 3:
                { // 修改离开时间
                    while (true)
                    {
                        cout << "请输入新的离开时间（格式：YYYY-MM-DD）：";
                        cin >> p->guest.check_out_time;
                        if (p->guest.check_out_time == "0")
                            return; // 取消操作

                        if (!IsValidDateString(p->guest.check_out_time))
                        {
                            cout << "离开时间格式错误，请重新输入！" << endl;
                            continue;
                        }
                        break;
                    }
                    break;
                }

                case 4:
                { // 修改房间编号
                    string original_room_number = p->guest.room_number;
                    while (true)
                    {
                        cout << "请输入新的房间编号：";
                        cin >> p->guest.room_number;
                        if (p->guest.room_number == "0")
                            return; // 取消操作

                        if (IsNewRoom(rhead, p->guest.room_number))
                        {
                            cout << "房间编号不存在，修改失败！" << endl;
                            continue;
                        }

                        // 检查新房间是否已有客人入住
                        room_node *r = rhead->next;
                        bool room_available = false;
                        while (r != nullptr)
                        {
                            if (r->room.room_number == p->guest.room_number)
                            {
                                if (r->room.room_status == 0)
                                {
                                    r->room.room_status = 1; // 将新房间标记为有人入住
                                    room_available = true;
                                    break;
                                }
                                else
                                {
                                    cout << "该房间已有客人入住，修改失败！" << endl;
                                    break;
                                }
                            }
                            r = r->next;
                        }

                        if (room_available)
                        {
                            // 处理原房间状态
                            room_node *q = rhead->next;
                            while (q != nullptr)
                            {
                                if (q->room.room_number == original_room_number)
                                {
                                    if (q->room.room_status == 1)
                                    {
                                        q->room.room_status = 0; // 将原房间状态改为无人
                                        break;
                                    }
                                    else
                                    {
                                        cout << "该客人没有入住该房间，修改失败！" << endl;
                                        return;
                                    }
                                }
                                q = q->next;
                            }
                            break;
                        }
                    }
                    break;
                }

                default:
                {
                    cout << "无效的选项，请重新输入！" << endl;
                    break; // 如果选择无效，重新提示输入
                }
                }

                break; // 成功修改后跳出循环
            }

            // 检查时间是否合法
            if (!CheckInAndOutTime(p->guest.check_in_time, p->guest.check_out_time))
            {
                p->guest.check_in_time = old_in;
                p->guest.check_out_time = old_out;
                cout << "时间不合法，已恢复原数据。" << endl;
                return;
            }

            // 重新计算费用
            ElemType new_total_cost = CalculateTotalCost(rhead, p->guest.room_number, p);
            p->guest.total_cost = new_total_cost;

            cout << "修改成功！" << endl;
            cout << "修改后的客人信息如下：" << endl;
            PrintGuestHeader();
            ShowGuestInfo(p);

            return; // 成功修改后退出函数
        }
        p = p->next;
    }
}

// 删除客人信息，用身份证号验证
void DeleteGuest(guest_node *ghead, room_node *rhead)
{
    string id;
    cout << "请输入要删除的客人身份证号：";
    cin >> id;
    guest_node *p = ghead->next;
    guest_node *prev = ghead;
    while (p != nullptr)
    {
        if (p->guest.id == id)
        {
            // 将对应房间状态改为无人
            string mark_number = p->guest.room_number;
            room_node *rp = rhead->next;
            bool found = false;
            while (rp != nullptr)
            {
                if (rp->room.room_number == mark_number)
                {
                    rp->room.room_status = 0;
                    cout << mark_number << "号房间现已无人！" << endl;
                    found = true;
                    break;
                }
                rp = rp->next;
            }
            if (!found)
            {
                cout << "未找到该房间信息。" << endl;
                return;
            }
            else
            { // 删除操作1
                prev->next = p->next;
                delete p;
                cout << "删除成功。" << endl;
                return;
            }
        }
        prev = p;
        p = p->next;
    }
    cout << "未找到该客人信息，删除失败！" << endl;
}

//------------------------------------------------客房操作-------------------------------------------------------
// 查询客房信息 ，有房间类型和价格区间两种方式
void FindRoom(room_node *head)
{
    string room_type;
    int room_price_min, room_price_max;
    ShowQueryRoomMenu();
    int choice;
    cout << "请输入操作指令：";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "请输入房间类型：";
        cin >> room_type;
        room_node *p = head->next;
        int count = 0;
        PrintRoomHeader();
        while (p != nullptr)
        {
            // 去除房间类型的尾部空格后再比较
            string type = p->room.room_type;
            // 去除尾部空格的函数
            size_t end_pos = type.find_last_not_of(' ');
            if (end_pos != string::npos)
            {
                type = type.substr(0, end_pos + 1);
            }

            if (type == room_type)
            {
                ShowRoomInfo(p);
                count++;
            }
            p = p->next;
        }
        if (count == 0)
        {
            cout << "---------------------------------" << endl;
            cout << "未找到该类型房间信息。" << endl;
        }
        break;
    }
    case 2:
    {
        cout << "请输入房间价格区间(最小值和最大值)：";
        cin >> room_price_min >> room_price_max;
        room_node *p = head->next;
        int count = 0;
        cout << left
             << setw(20) << "房间编号"
             << setw(20) << "房间类型"
             << setw(20) << "房间价格"
             << setw(20) << "房间状态"
             << endl;
        while (p != nullptr)
        {
            if (p->room.room_price >= room_price_min && p->room.room_price <= room_price_max)
            {
                cout << left
                     << setw(15) << p->room.room_number
                     << setw(15) << p->room.room_type
                     << setw(15) << p->room.room_price
                     << setw(15) << p->room.room_status
                     << endl;
                count++;
            }
            p = p->next;
        }
        if (count == 0)
        {
            cout << "---------------------------------" << endl;
            cout << "未找到该价格区间房间信息。" << endl;
        }
        break;
    }
    case 3:
    {
        return;
    }
    default:
    {
        cout << "输入错误！请重新输入！" << endl;
        break;
    }
    }
}

// 新增客房信息，用房间编号检测
void AddRoom(room_node *head)
{
    Room new_room;
    string room_number;

    /* ---------- 房间编号输入（循环校验） ---------- */
    while (true)
    {
        cout << "请输入新增客房编号：";
        cin >> room_number;

        if (room_number == "0")
        {
            return;
        }

        if (!IsNewRoom(head, room_number))
        {
            cout << "该房间编号已存在，请重新输入！" << endl;
        }
        else
        {
            new_room.room_number = room_number;
            break;
        }
    }

    /* ---------- 房间类型输入 ---------- */
    while (true)
    {
        cout << "请输入房间类型：";
        cin >> new_room.room_type;

        if (new_room.room_type.empty())
        {
            cout << "房间类型不能为空，请重新输入！" << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    /* ---------- 房间价格输入 ---------- */
    while (true)
    {
        cout << "请输入房间价格：";
        cin >> new_room.room_price;

        if (new_room.room_price <= 0)
        {
            cout << "房间价格必须大于 0，请重新输入！" << endl;
        }
        else
        {
            break;
        }
    }

    /* ---------- 初始化房间状态 ---------- */
    new_room.room_status = 0;

    /* ---------- 插入链表尾部 ---------- */
    room_node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }

    room_node *new_node = new room_node;
    new_node->room = new_room;
    new_node->next = nullptr;
    p->next = new_node;

    cout << "新房间添加成功！" << endl;
}

// 修改客房信息，用房间编号检测
void ModifyRoom(room_node *head)
{
    string room_number;
    room_node *target = nullptr;

    /* ---------- 输入房间编号 ---------- */
    while (true)
    {
        cout << "请输入要修改的客房编号：";
        cin >> room_number;

        if (room_number == "0")
        {
            return;
        }

        if (IsNewRoom(head, room_number))
        {
            cout << "该房间编号不存在，请重新输入！" << endl;
        }
        else
        {
            room_node *p = head->next;
            while (p != nullptr)
            {
                if (p->room.room_number == room_number)
                {
                    target = p;
                    break;
                }
                p = p->next;
            }

            if (target != nullptr)
            {
                break;
            }
        }
    }

    /* ---------- 菜单选择 ---------- */
    while (true)
    {
        int choice;
        ShowModifyRoomMenu();
        cout << "请输入修改内容：";
        cin >> choice;

        if (choice == 0)
        {
            return;
        }

        switch (choice)
        {
        case 1:
        {
            while (true)
            {
                cout << "请输入新的房间类型：";
                cin >> target->room.room_type;

                if (target->room.room_type.empty())
                {
                    cout << "房间类型不能为空，请重新输入！" << endl;
                }
                else
                {
                    break;
                }
            }
            break;
        }
        case 2:
        {
            while (true)
            {
                cout << "请输入新的房间价格：";
                cin >> target->room.room_price;

                if (target->room.room_price <= 0)
                {
                    cout << "房间价格必须大于 0，请重新输入！" << endl;
                }
                else
                {
                    break;
                }
            }
            break;
        }
        case 3:
        {
            return;
        }
        default:
        {
            cout << "无效选项，请重新选择。" << endl;
            continue;
        }
        }

        cout << "房间信息修改成功！" << endl;
    }
}

//------------------------------------------------子菜单-------------------------------------------------------
// 客房子菜单
void RoomMenu(room_node *room_head)
{
    int second_step;
    while (true)
    {
        ShowRoomMenu();
        cout << "请输入操作指令：";
        cin >> second_step;
        switch (second_step)
        {
        // 添加房间信息
        case 1:
        {
            AddRoom(room_head);
            SaveRooms(room_head);
            break;
        }
        // 修改房间信息
        case 2:
        {
            ModifyRoom(room_head);
            SaveRooms(room_head);
            break;
        }
        // 查询房间信息
        case 3:
        {
            FindRoom(room_head);
            SaveRooms(room_head);
            break;
        }
        // 返回上级菜单
        case 4:
        {
            return;
        }
        default:
        {
            cout << "输入错误！请重新输入！" << endl;
            break;
        }
        }
    }
}

// 客人子菜单
void GuestMenu(guest_node *guest_head, room_node *room_head)
{
    int second_step;
    while (true)
    {
        ShowGuestMenu();
        cout << "请输入操作指令：";
        cin >> second_step;
        switch (second_step)
        {
        // 添加客人信息
        case 1:
        {
            AddGuest(guest_head, room_head);
            SaveGuests(guest_head);
            SaveRooms(room_head);
            break;
        }
        // 删除客人信息
        case 2:
        {
            DeleteGuest(guest_head, room_head);
            SaveGuests(guest_head);
            SaveRooms(room_head);
            break;
        }
        // 修改客人信息
        case 3:
        {
            ModifyGuest(guest_head, room_head);
            SaveGuests(guest_head);
            SaveRooms(room_head);
            break;
        }
        // 查询客人信息
        case 4:
        {
            FindGuest(guest_head, room_head);
            SaveGuests(guest_head);
            SaveRooms(room_head);
            break;
        }
        // 显示所有客人信息
        case 5:
        {
            ShowAllGuests(guest_head, room_head);
            SaveGuests(guest_head);
            SaveRooms(room_head);
            break;
        }
        // 返回上级菜单
        case 6:
        {
            return;
        }
        default:
        {
            cout << "输入错误！请重新输入！" << endl;
            break;
        }
        }
    }
}

//------------------------------------------------主程序-------------------------------------------------------
int main()
{
    SetConsoleOutputCP(65001); // 设置控制台为 UTF-8
    // 初始化头结点
    guest_node *guest_head = new guest_node{{}, nullptr};
    room_node *room_head = new room_node{{}, nullptr};

    // 从文件读取数据
    int rReturn = LoadRoomsFromFile(room_head, "room.txt");
    int gReturn = LoadGuestsFromFile(guest_head, "guests.txt");
    if (rReturn == 0 && gReturn == 0)
    {
        cout << "数据加载成功。" << endl;
    }
    else
    {
        cout << "数据加载失败。" << endl;
    }

    int first_step;
    while (true)
    {
        ShowMenu();
        cout << "请输入操作指令：";
        cin >> first_step;

        if (first_step == 0)
        {
            cout << "更新完成，欢迎下次使用。" << endl;
            cout << ascii_art::complex_ascii_art << endl;
            break; // 跳出 while
        }
        else if (first_step == 1)
        {
            GuestMenu(guest_head, room_head);
        }
        else if (first_step == 2)
        {
            RoomMenu(room_head);
        }
        else
        {
            cout << "输入错误！请重新输入！" << endl;
        }
    }

    return 0;
}