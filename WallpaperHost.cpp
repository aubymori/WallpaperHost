#include <windows.h>
#include <shlobj.h>
#include "ActiveDesktopWallpaperHost.h"

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,
	int       nCmdShow
)
{
	if (FAILED(CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE)))
	{
		CoInitializeEx(nullptr, COINIT_DISABLE_OLE1DDE);
	}

	IActiveDesktopWallpaperHost *padwh = nullptr;
	if (SUCCEEDED(CoCreateInstance(CLSID_ActiveDesktop, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&padwh))))
	{
		padwh->RunWallpaperHostSynchronous();
		padwh->Release();
	}

	CoUninitialize();
	return 1;
}