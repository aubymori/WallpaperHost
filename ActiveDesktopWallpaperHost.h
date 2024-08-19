#pragma once
#include <windows.h>

DEFINE_GUID(IID_IActiveDesktopWallpaperHost, 0x7E2EA1C2, 0x809E, 0x4B09, 0x9A, 0x0D, 0x7A, 0x1B, 0x23, 0x82, 0x63, 0xDA);

MIDL_INTERFACE("7E2EA1C2-809E-4B09-9A0D-7A1B238263DA")
IActiveDesktopWallpaperHost : IUnknown
{
public:
    virtual HRESULT RunWallpaperHostSynchronous() = 0;
};