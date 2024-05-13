// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <d3d9.h>
#include "IDirect3D9.h"


typedef IDirect3D9* (WINAPI* fn_D3D9Direct3DCreate9)(UINT SDKVersion);
// HookDirect3D9* hookDirect3D9;
HMODULE d3d_dll;

fn_D3D9Direct3DCreate9 LoadD3D9AndGetOriginalFuncPointer()
{
	char path[MAX_PATH];
	if (!GetSystemDirectoryA(path, MAX_PATH)) return nullptr;

	strcat_s(path, MAX_PATH * sizeof(char), "\\d3d9.dll");
	d3d_dll = LoadLibraryA(path);

	if (!d3d_dll)
	{
		MessageBox(NULL, TEXT("Could Not Locate Original D3D9 DLL"), TEXT("Darn"), 0);
		return nullptr;
	}

	return (fn_D3D9Direct3DCreate9)GetProcAddress(d3d_dll, LPCSTR("Direct3DCreate9"));
}

IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
	// MessageBox(NULL, TEXT("Hooked Direct3DCreate9"), TEXT("Success"), 0);
	fn_D3D9Direct3DCreate9 D3D9Direct3DCreate9_Orig = LoadD3D9AndGetOriginalFuncPointer();
	
	IDirect3D9* originalIDirect3D9 = D3D9Direct3DCreate9_Orig(SDKVersion);

	HookDirect3D9* myIDirect3D9 = new HookDirect3D9(originalIDirect3D9);

	return myIDirect3D9;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

