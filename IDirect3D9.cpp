#include <d3d9.h>
#include "IDirect3D9.h"
#include "IDirect3D9Device9.h"


HookDirect3D9::HookDirect3D9(IDirect3D9* originalPointer) {
	hookPointer = originalPointer;
}

HookDirect3D9::~HookDirect3D9(void) {}

HRESULT __stdcall HookDirect3D9::QueryInterface(REFIID riid, void** ppvObj)
{
	return hookPointer->QueryInterface(riid, ppvObj);
}

ULONG __stdcall HookDirect3D9::AddRef(void)
{
	return hookPointer->AddRef();
}

ULONG __stdcall HookDirect3D9::Release(void)
{
	return hookPointer->Release();
}

HRESULT __stdcall HookDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return hookPointer->RegisterSoftwareDevice(pInitializeFunction);
}

UINT __stdcall HookDirect3D9::GetAdapterCount(void)
{
	return hookPointer->GetAdapterCount();
}

HRESULT __stdcall HookDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return hookPointer->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT __stdcall HookDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
	return hookPointer->GetAdapterModeCount(Adapter, Format);
}

HRESULT __stdcall HookDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
	return hookPointer->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

HRESULT __stdcall HookDirect3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
	return hookPointer->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT __stdcall HookDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
	return hookPointer->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
}

HRESULT __stdcall HookDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
	return hookPointer->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT __stdcall HookDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
	return hookPointer->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed,  MultiSampleType, pQualityLevels);
}

HRESULT __stdcall HookDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
	return hookPointer->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT __stdcall HookDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
	return hookPointer->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT __stdcall HookDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
	return hookPointer->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR __stdcall HookDirect3D9::GetAdapterMonitor(UINT Adapter)
{
	return hookPointer->GetAdapterMonitor(Adapter);
}

HRESULT __stdcall HookDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	// MessageBox(NULL, TEXT("Hooked CreateDevice"), TEXT("Success"), 0);
	

	HRESULT hres = hookPointer->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

	HookDirect3D9Device9* hookIDirect3DDevice9 = new HookDirect3D9Device9(*ppReturnedDeviceInterface);

	*ppReturnedDeviceInterface = hookIDirect3DDevice9;

	return hres;
}
