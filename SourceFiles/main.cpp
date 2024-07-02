
#include"../HeaderFiles/parser.h"
#include"../HeaderFiles/objectivecode.h"
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <codecvt>

using namespace std;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hwndInput, hwndOutput1, hwndOutput2, hwndOutput3, hwndButton1, hwndButton2, hwndButton3;
wstring file_strings = L"Table Sequence: ";
wstring file_names = L"Table Sequence: ";
wstring table = L"Table Sequence: ";
wstring token = L"Token Sequence: ";
wstring grammer = L"Check Grammar: ";
wstring synbl1 = L"SYNBL: ";
wstring synbl2 = L"SYNBL: ";
wstring quaternion = L"Quaternion: ";
wstring ActiveRecording = L"Active Recording:";
wstring blockOutput = L"Optimize Qua:";
wstring ActInf = L"Active Information:";
wstring ActSynbl = L"Active Synbl:";
wstring quaof = L"Quadruple Form:";
wstring Objective_Code = L"Objective_Code:";

void ClearWindow(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"NEU Compiler",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 1200, 700,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

void ClearWindow(HWND hwnd)
{
    HWND hwndChild = GetWindow(hwnd, GW_CHILD);
    while (hwndChild)
    {
        DestroyWindow(hwndChild);
        hwndChild = GetWindow(hwnd, GW_CHILD);
    }
}

void ShowInterface1(HWND hwnd)
{
    // 设置窗口标题为 "NEU Compiler"
    SetWindowText(hwnd, L"NEU Compiler");

    ClearWindow(hwnd);
    // 小标题
    CreateWindow(L"STATIC", L"NEU Compiler", WS_CHILD | WS_VISIBLE, 550, 40, 100, 40, hwnd, NULL, NULL, NULL);
    CreateWindow(L"STATIC", file_names.c_str(), WS_CHILD | WS_VISIBLE, 250, 180, 700, 20, hwnd, NULL, NULL, NULL);
    hwndOutput1 = CreateWindow(L"STATIC", file_strings.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 250, 200, 700, 300, hwnd, NULL, NULL, NULL);
    hwndButton1 = CreateWindow(L"BUTTON", L"确定", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 600, 100, 50, hwnd, (HMENU)1, NULL, NULL);
}


void ShowInterface2(HWND hwnd)
{
    // 创建一个1200x700的白色窗口
    RECT rect;
    GetClientRect(hwnd, &rect);
    HDC hdc = GetDC(hwnd);
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255)); // 白色刷子
    RECT whiteRect = { 0, 0, 1200, 700 };
    FillRect(hdc, &whiteRect, brush);
    ReleaseDC(hwnd, hdc);
    DeleteObject(brush);

    // 清理窗口
    ClearWindow(hwnd);
    CreateWindow(L"STATIC", L"词法分析", WS_CHILD | WS_VISIBLE, 550, 40, 100, 40, hwnd, NULL, NULL, NULL);

    // 小标题
    CreateWindow(L"STATIC", L"Table Sequence:", WS_CHILD | WS_VISIBLE, 75, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput1 = CreateWindow(L"STATIC", table.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 75, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Token Sequence:", WS_CHILD | WS_VISIBLE, 335, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput2 = CreateWindow(L"STATIC", token.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 335, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Check Grammar:", WS_CHILD | WS_VISIBLE, 605, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput3 = CreateWindow(L"STATIC", grammer.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 605, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"SYNBL:", WS_CHILD | WS_VISIBLE, 875, 100, 250, 20, hwnd, NULL, NULL, NULL);
    CreateWindow(L"STATIC", synbl1.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 875, 125, 250, 450, hwnd, NULL, NULL, NULL);

    hwndButton2 = CreateWindow(L"BUTTON", L"Continue", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 600, 100, 50, hwnd, (HMENU)2, NULL, NULL);
}

void ShowInterface3(HWND hwnd)
{
    ClearWindow(hwnd);
    CreateWindow(L"STATIC", L"中间代码生成及代码优化", WS_CHILD | WS_VISIBLE, 550, 40, 100, 40, hwnd, NULL, NULL, NULL);

    // 小标题
    CreateWindow(L"STATIC", L"Quaternion:", WS_CHILD | WS_VISIBLE, 75, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput1 = CreateWindow(L"STATIC", quaternion.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 75, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Active Recording:", WS_CHILD | WS_VISIBLE, 335, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput2 = CreateWindow(L"STATIC", ActiveRecording.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 335, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Optimize Qua:", WS_CHILD | WS_VISIBLE, 605, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput3 = CreateWindow(L"STATIC", blockOutput.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 605, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"SYNBL:", WS_CHILD | WS_VISIBLE, 875, 100, 250, 20, hwnd, NULL, NULL, NULL);
    CreateWindow(L"STATIC", synbl2.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 875, 125, 250, 450, hwnd, NULL, NULL, NULL);

    hwndButton3 = CreateWindow(L"BUTTON", L"Continue", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 600, 100, 50, hwnd, (HMENU)3, NULL, NULL);
}

void ShowInterface4(HWND hwnd)
{
    ClearWindow(hwnd);
    CreateWindow(L"STATIC", L"目标代码生成", WS_CHILD | WS_VISIBLE, 550, 40, 100, 40, hwnd, NULL, NULL, NULL);

    // 小标题
    CreateWindow(L"STATIC", L"Active Information:", WS_CHILD | WS_VISIBLE, 75, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput1 = CreateWindow(L"STATIC", ActInf.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 75, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Active Synbl:", WS_CHILD | WS_VISIBLE, 335, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput2 = CreateWindow(L"STATIC", ActSynbl.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 335, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Quadruple Form:", WS_CHILD | WS_VISIBLE, 605, 100, 250, 20, hwnd, NULL, NULL, NULL);
    hwndOutput3 = CreateWindow(L"STATIC", quaof.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 605, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Objective_Code:", WS_CHILD | WS_VISIBLE, 875, 100, 250, 20, hwnd, NULL, NULL, NULL);
    CreateWindow(L"STATIC", Objective_Code.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 875, 125, 250, 450, hwnd, NULL, NULL, NULL);

    CreateWindow(L"BUTTON", L"Finish", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 600, 100, 50, hwnd, (HMENU)4, NULL, NULL);
}


void PerformAnalysis()
{
    vector<QuaternionNode> qua;
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    //string file_string_str = converter.to_bytes(file_string);


    string file_name = "test2.txt";
    ifstream input_file(file_name);
    string file_string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());

    file_names = converter.from_bytes(file_name);
    file_strings = converter.from_bytes(file_string);

    // 词法分析
    Parser parser(file_string);
    parser.init_symbol();
    synbl1 = converter.from_bytes(parser.synbl_print());
    table = converter.from_bytes(parser.ShowTable());
    token = converter.from_bytes(parser.Print_Token());
    grammer = converter.from_bytes(parser.checkGrammar());
    synbl2 = converter.from_bytes(parser.synbl_print());

    // 中间代码生成及代码优化
    quaternion = converter.from_bytes(parser.printQuaternion());
    ActiveRecording = converter.from_bytes(parser.printRecording());
    qua = parser.getQuaternion();
    objective ob;
    ob.init(qua);
    blockOutput = converter.from_bytes(ob.optimizequa(ob.divide()));

    // 目标代码生成
    ob.process_blocks();
    ActInf = converter.from_bytes(ob.printActInf());
    ActSynbl = converter.from_bytes(ob.printActSynbl());
    quaof = converter.from_bytes(ob.printQua());
    Objective_Code = converter.from_bytes(ob.Objective_Code(ob.qua, ob.Act_inf));

}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        PerformAnalysis();
        ShowInterface1(hwnd);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1:
        {
            ShowInterface2(hwnd);
            break;
        }
        case 2:
            ShowInterface3(hwnd);
            break;
        case 3:
            ShowInterface4(hwnd);
            break;
        case 4:
            PostQuitMessage(0);
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



