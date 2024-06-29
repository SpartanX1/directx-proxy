#include "IDirect3D9Device9.h"
#include <D3dx9core.h>
#include <string>
#include <chrono>
#include <thread>

INT frames = 0;
INT lastFrame = 0;
auto ts = std::chrono::system_clock::now() + std::chrono::seconds(1);
auto fiveseconds = std::chrono::system_clock::now() + std::chrono::seconds(2);
LPD3DXFONT	m_font;
D3DCOLOR fontColor;
RECT rct;

HookDirect3D9Device9::HookDirect3D9Device9(IDirect3DDevice9* pOriginal)
{
    hookPointer = pOriginal; // store the pointer to original object

    // Define fonts and color
    m_font = NULL;
    D3DXCreateFont(hookPointer, 17, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &m_font);
    fontColor = D3DCOLOR_ARGB(255, 255, 255, 0);

    rct.left = 40;
    rct.right = 1680;
    rct.top = 40;
    rct.bottom = rct.top + 200;
}

HookDirect3D9Device9::~HookDirect3D9Device9(void)
{
}

HRESULT HookDirect3D9Device9::QueryInterface(REFIID riid, void** ppvObj)
{
    return hookPointer->QueryInterface(riid, ppvObj);
}

ULONG HookDirect3D9Device9::AddRef(void)
{
    return(hookPointer->AddRef());
}

ULONG HookDirect3D9Device9::Release(void)
{
    return hookPointer->Release();
}

HRESULT HookDirect3D9Device9::TestCooperativeLevel(void)
{
    return(hookPointer->TestCooperativeLevel());
}

UINT HookDirect3D9Device9::GetAvailableTextureMem(void)
{
    return(hookPointer->GetAvailableTextureMem());
}

HRESULT HookDirect3D9Device9::EvictManagedResources(void)
{
    return(hookPointer->EvictManagedResources());
}

HRESULT HookDirect3D9Device9::GetDirect3D(IDirect3D9** ppD3D9)
{
    return(hookPointer->GetDirect3D(ppD3D9));
}

HRESULT HookDirect3D9Device9::GetDeviceCaps(D3DCAPS9* pCaps)
{
    return(hookPointer->GetDeviceCaps(pCaps));
}

HRESULT HookDirect3D9Device9::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
    return(hookPointer->GetDisplayMode(iSwapChain, pMode));
}

HRESULT HookDirect3D9Device9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
    return(hookPointer->GetCreationParameters(pParameters));
}

HRESULT HookDirect3D9Device9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
    return(hookPointer->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap));
}

void    HookDirect3D9Device9::SetCursorPosition(int X, int Y, DWORD Flags)
{
    return(hookPointer->SetCursorPosition(X, Y, Flags));
}

BOOL    HookDirect3D9Device9::ShowCursor(BOOL bShow)
{
    return(hookPointer->ShowCursor(bShow));
}

HRESULT HookDirect3D9Device9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
    return(hookPointer->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain));
}

HRESULT HookDirect3D9Device9::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
    return hookPointer->GetSwapChain(iSwapChain, pSwapChain);
}

UINT    HookDirect3D9Device9::GetNumberOfSwapChains(void)
{
    return(hookPointer->GetNumberOfSwapChains());
}

HRESULT HookDirect3D9Device9::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return(hookPointer->Reset(pPresentationParameters));
}

HRESULT HookDirect3D9Device9::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
  
  //  D3DRECT rec = { 1,1,50,50 };
  //  hookPointer->Clear(1, &rec, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 255, 255, 0), 0, 0);
    return hookPointer->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT HookDirect3D9Device9::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    return(hookPointer->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer));
}

HRESULT HookDirect3D9Device9::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
    return(hookPointer->GetRasterStatus(iSwapChain, pRasterStatus));
}

HRESULT HookDirect3D9Device9::SetDialogBoxMode(BOOL bEnableDialogs)
{
    return(hookPointer->SetDialogBoxMode(bEnableDialogs));
}

void    HookDirect3D9Device9::SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
    return(hookPointer->SetGammaRamp(iSwapChain, Flags, pRamp));
}

void    HookDirect3D9Device9::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
    return(hookPointer->GetGammaRamp(iSwapChain, pRamp));
}

HRESULT HookDirect3D9Device9::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle));
}

HRESULT HookDirect3D9Device9::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle));
}

HRESULT HookDirect3D9Device9::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle));
}

HRESULT HookDirect3D9Device9::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle));
}

HRESULT HookDirect3D9Device9::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle));
}

HRESULT HookDirect3D9Device9::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle));
}

HRESULT HookDirect3D9Device9::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle));
}

HRESULT HookDirect3D9Device9::UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
    return(hookPointer->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint));
}

HRESULT HookDirect3D9Device9::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    return(hookPointer->UpdateTexture(pSourceTexture, pDestinationTexture));
}

HRESULT HookDirect3D9Device9::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
    return(hookPointer->GetRenderTargetData(pRenderTarget, pDestSurface));
}

HRESULT HookDirect3D9Device9::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
    return(hookPointer->GetFrontBufferData(iSwapChain, pDestSurface));
}

HRESULT HookDirect3D9Device9::StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    return(hookPointer->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter));
}

HRESULT HookDirect3D9Device9::ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
    return(hookPointer->ColorFill(pSurface, pRect, color));
}

HRESULT HookDirect3D9Device9::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return(hookPointer->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle));
}

HRESULT HookDirect3D9Device9::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
    return(hookPointer->SetRenderTarget(RenderTargetIndex, pRenderTarget));
}

HRESULT HookDirect3D9Device9::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
    return(hookPointer->GetRenderTarget(RenderTargetIndex, ppRenderTarget));
}

HRESULT HookDirect3D9Device9::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
    return(hookPointer->SetDepthStencilSurface(pNewZStencil));
}

HRESULT HookDirect3D9Device9::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
    return(hookPointer->GetDepthStencilSurface(ppZStencilSurface));
}

HRESULT HookDirect3D9Device9::BeginScene(void)
{
    return(hookPointer->BeginScene());
}

HRESULT HookDirect3D9Device9::EndScene(void)
{
    
    if (ts <= std::chrono::system_clock::now()) {
        lastFrame = frames;
        frames = 0;
        ts += std::chrono::seconds(1);

        if (fiveseconds <= std::chrono::system_clock::now()) {
            m_font->DrawTextA(NULL, std::to_string(lastFrame).c_str(), -1, &rct, 0, fontColor);
            fiveseconds += std::chrono::seconds(2);
        }
    }
    else {
        frames++;
        m_font->DrawTextA(NULL, std::to_string(lastFrame).c_str(), -1, &rct, 0, fontColor);
    }

    return(hookPointer->EndScene());
}

HRESULT HookDirect3D9Device9::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    return(hookPointer->Clear(Count, pRects, Flags, Color, Z, Stencil));
}

HRESULT HookDirect3D9Device9::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    return(hookPointer->SetTransform(State, pMatrix));
}

HRESULT HookDirect3D9Device9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    return(hookPointer->GetTransform(State, pMatrix));
}

HRESULT HookDirect3D9Device9::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    return(hookPointer->MultiplyTransform(State, pMatrix));
}

HRESULT HookDirect3D9Device9::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
    return(hookPointer->SetViewport(pViewport));
}

HRESULT HookDirect3D9Device9::GetViewport(D3DVIEWPORT9* pViewport)
{
    return(hookPointer->GetViewport(pViewport));
}

HRESULT HookDirect3D9Device9::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
    return(hookPointer->SetMaterial(pMaterial));
}

HRESULT HookDirect3D9Device9::GetMaterial(D3DMATERIAL9* pMaterial)
{
    return(hookPointer->GetMaterial(pMaterial));
}

HRESULT HookDirect3D9Device9::SetLight(DWORD Index, CONST D3DLIGHT9* pLight)
{
    return(hookPointer->SetLight(Index, pLight));
}

HRESULT HookDirect3D9Device9::GetLight(DWORD Index, D3DLIGHT9* pLight)
{
    return(hookPointer->GetLight(Index, pLight));
}

HRESULT HookDirect3D9Device9::LightEnable(DWORD Index, BOOL Enable)
{
    return(hookPointer->LightEnable(Index, Enable));
}

HRESULT HookDirect3D9Device9::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    return(hookPointer->GetLightEnable(Index, pEnable));
}

HRESULT HookDirect3D9Device9::SetClipPlane(DWORD Index, CONST float* pPlane)
{
    return(hookPointer->SetClipPlane(Index, pPlane));
}

HRESULT HookDirect3D9Device9::GetClipPlane(DWORD Index, float* pPlane)
{
    return(hookPointer->GetClipPlane(Index, pPlane));
}

HRESULT HookDirect3D9Device9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    return(hookPointer->SetRenderState(State, Value));
}

HRESULT HookDirect3D9Device9::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    return(hookPointer->GetRenderState(State, pValue));
}

HRESULT HookDirect3D9Device9::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
    return(hookPointer->CreateStateBlock(Type, ppSB));
}

HRESULT HookDirect3D9Device9::BeginStateBlock(void)
{
    return(hookPointer->BeginStateBlock());
}

HRESULT HookDirect3D9Device9::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
    return(hookPointer->EndStateBlock(ppSB));
}

HRESULT HookDirect3D9Device9::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
    return(hookPointer->SetClipStatus(pClipStatus));
}

HRESULT HookDirect3D9Device9::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
    return(hookPointer->GetClipStatus(pClipStatus));
}

HRESULT HookDirect3D9Device9::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    return(hookPointer->GetTexture(Stage, ppTexture));
}

HRESULT HookDirect3D9Device9::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    return(hookPointer->SetTexture(Stage, pTexture));
}

HRESULT HookDirect3D9Device9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    return(hookPointer->GetTextureStageState(Stage, Type, pValue));
}

HRESULT HookDirect3D9Device9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    return(hookPointer->SetTextureStageState(Stage, Type, Value));
}

HRESULT HookDirect3D9Device9::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
    return(hookPointer->GetSamplerState(Sampler, Type, pValue));
}

HRESULT HookDirect3D9Device9::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    return(hookPointer->SetSamplerState(Sampler, Type, Value));
}

HRESULT HookDirect3D9Device9::ValidateDevice(DWORD* pNumPasses)
{
    return(hookPointer->ValidateDevice(pNumPasses));
}

HRESULT HookDirect3D9Device9::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
{
    return(hookPointer->SetPaletteEntries(PaletteNumber, pEntries));
}

HRESULT HookDirect3D9Device9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    return(hookPointer->GetPaletteEntries(PaletteNumber, pEntries));
}

HRESULT HookDirect3D9Device9::SetCurrentTexturePalette(UINT PaletteNumber)
{
    return(hookPointer->SetCurrentTexturePalette(PaletteNumber));
}

HRESULT HookDirect3D9Device9::GetCurrentTexturePalette(UINT* PaletteNumber)
{
    return(hookPointer->GetCurrentTexturePalette(PaletteNumber));
}

HRESULT HookDirect3D9Device9::SetScissorRect(CONST RECT* pRect)
{
    return(hookPointer->SetScissorRect(pRect));
}

HRESULT HookDirect3D9Device9::GetScissorRect(RECT* pRect)
{
    return(hookPointer->GetScissorRect(pRect));
}

HRESULT HookDirect3D9Device9::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    return(hookPointer->SetSoftwareVertexProcessing(bSoftware));
}

BOOL    HookDirect3D9Device9::GetSoftwareVertexProcessing(void)
{
    return(hookPointer->GetSoftwareVertexProcessing());
}

HRESULT HookDirect3D9Device9::SetNPatchMode(float nSegments)
{
    return(hookPointer->SetNPatchMode(nSegments));
}

float   HookDirect3D9Device9::GetNPatchMode(void)
{
    return(hookPointer->GetNPatchMode());
}

HRESULT HookDirect3D9Device9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    return(hookPointer->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount));
}

HRESULT HookDirect3D9Device9::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return(hookPointer->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount));
}

HRESULT HookDirect3D9Device9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return(hookPointer->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride));
}

HRESULT HookDirect3D9Device9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return(hookPointer->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride));
}

HRESULT HookDirect3D9Device9::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
    return(hookPointer->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags));
}

HRESULT HookDirect3D9Device9::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    return(hookPointer->CreateVertexDeclaration(pVertexElements, ppDecl));
}

HRESULT HookDirect3D9Device9::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
    return(hookPointer->SetVertexDeclaration(pDecl));
}

HRESULT HookDirect3D9Device9::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
    return(hookPointer->GetVertexDeclaration(ppDecl));
}

HRESULT HookDirect3D9Device9::SetFVF(DWORD FVF)
{
    return(hookPointer->SetFVF(FVF));
}

HRESULT HookDirect3D9Device9::GetFVF(DWORD* pFVF)
{
    return(hookPointer->GetFVF(pFVF));
}

HRESULT HookDirect3D9Device9::CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    return(hookPointer->CreateVertexShader(pFunction, ppShader));
}

HRESULT HookDirect3D9Device9::SetVertexShader(IDirect3DVertexShader9* pShader)
{
    return(hookPointer->SetVertexShader(pShader));
}

HRESULT HookDirect3D9Device9::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
    return(hookPointer->GetVertexShader(ppShader));
}

HRESULT HookDirect3D9Device9::SetVertexShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
    return(hookPointer->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount));
}

HRESULT HookDirect3D9Device9::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    return(hookPointer->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount));
}

HRESULT HookDirect3D9Device9::SetVertexShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
    return(hookPointer->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount));
}

HRESULT HookDirect3D9Device9::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    return(hookPointer->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount));
}

HRESULT HookDirect3D9Device9::SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
{
    return(hookPointer->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount));
}

HRESULT HookDirect3D9Device9::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    return(hookPointer->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount));
}

HRESULT HookDirect3D9Device9::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
    return(hookPointer->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride));
}

HRESULT HookDirect3D9Device9::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride)
{
    return(hookPointer->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride));
}

HRESULT HookDirect3D9Device9::SetStreamSourceFreq(UINT StreamNumber, UINT Divider)
{
    return(hookPointer->SetStreamSourceFreq(StreamNumber, Divider));
}

HRESULT HookDirect3D9Device9::GetStreamSourceFreq(UINT StreamNumber, UINT* Divider)
{
    return(hookPointer->GetStreamSourceFreq(StreamNumber, Divider));
}

HRESULT HookDirect3D9Device9::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
    return(hookPointer->SetIndices(pIndexData));
}

HRESULT HookDirect3D9Device9::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
    return(hookPointer->GetIndices(ppIndexData));
}

HRESULT HookDirect3D9Device9::CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    return(hookPointer->CreatePixelShader(pFunction, ppShader));
}

HRESULT HookDirect3D9Device9::SetPixelShader(IDirect3DPixelShader9* pShader)
{
    return(hookPointer->SetPixelShader(pShader));
}

HRESULT HookDirect3D9Device9::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
    return(hookPointer->GetPixelShader(ppShader));
}

HRESULT HookDirect3D9Device9::SetPixelShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
    return(hookPointer->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount));
}

HRESULT HookDirect3D9Device9::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
    return(hookPointer->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount));
}

HRESULT HookDirect3D9Device9::SetPixelShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
    return(hookPointer->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount));
}

HRESULT HookDirect3D9Device9::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
    return(hookPointer->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount));
}

HRESULT HookDirect3D9Device9::SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
{
    return(hookPointer->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount));
}

HRESULT HookDirect3D9Device9::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
    return(hookPointer->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount));
}

HRESULT HookDirect3D9Device9::DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
    return(hookPointer->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo));
}

HRESULT HookDirect3D9Device9::DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
    return(hookPointer->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo));
}

HRESULT HookDirect3D9Device9::DeletePatch(UINT Handle)
{
    return(hookPointer->DeletePatch(Handle));
}

HRESULT HookDirect3D9Device9::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    return(hookPointer->CreateQuery(Type, ppQuery));
}



