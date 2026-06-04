#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

const wchar_t mainMessage[] = L"Salut lume!";

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
    const wchar_t className[] = L"Win32WindowClass";

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(0, 128, 0));
    wc.lpszClassName = className;

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, L"Window class registration failed!", L"Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    HWND hMainWnd = CreateWindowEx(
        0,
        className,
        L"Win32 API Text Rendering",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        500,
        NULL,
        NULL,
        hInst,
        NULL
    );

    if (!hMainWnd)
    {
        MessageBox(NULL, L"Window creation failed!", L"Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    ShowWindow(hMainWnd, nCmdShow);
    UpdateWindow(hMainWnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        RECT rect;
        GetClientRect(hWnd, &rect);

        SetBkMode(hdc, TRANSPARENT);

        // Centered green text
        SetTextColor(hdc, RGB(0, 255, 0));
        DrawText(
            hdc,
            L"Mesaj centrat de culoare verde",
            -1,
            &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER
        );

        // Top-right violet text
        RECT topRightRect = rect;
        topRightRect.top = 20;
        topRightRect.right -= 20;

        SetTextColor(hdc, RGB(128, 0, 128));
        DrawText(
            hdc,
            L"Mesaj violet aliniat dreapta sus",
            -1,
            &topRightRect,
            DT_SINGLELINE | DT_RIGHT | DT_TOP
        );

        // Top-left yellow text
        RECT topLeftRect = rect;
        topLeftRect.left += 20;
        topLeftRect.top = 20;

        SetTextColor(hdc, RGB(255, 255, 0));
        DrawText(
            hdc,
            L"Mesaj galben aliniat stanga sus",
            -1,
            &topLeftRect,
            DT_SINGLELINE | DT_LEFT | DT_TOP
        );

        // Red text on green background requirement
        RECT bottomRect = rect;
        bottomRect.bottom -= 30;

        SetTextColor(hdc, RGB(255, 0, 0));
        DrawText(
            hdc,
            L"Fereastra are fundal verde si mesaj rosu",
            -1,
            &bottomRect,
            DT_SINGLELINE | DT_CENTER | DT_BOTTOM
        );

        EndPaint(hWnd, &ps);
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
