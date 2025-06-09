#define CLAY_IMPLEMENTATION
#include "../../clay.h"
#include "../../renderers/raylib/clay_renderer_raylib.c"

static bool ScreenSizeChanged = true;

typedef enum renderType
{
    Model,
    Texture,
} 

void MyCustomRenderCommand(Clay_RenderCommand *renderCommand)
{

}

int main(void) 
{
    Clay_Raylib_Initialize(1024, 768, "Raylib - Custom Render Commands Demo", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT); // Extra parameters to this function are new since the video was published

    Font fonts[1];
    fonts[FONT_ID_BODY_16] = LoadFontEx("resources/Roboto-Regular.ttf", 48, 0, 400);
    SetTextureFilter(fonts[FONT_ID_BODY_16].texture, TEXTURE_FILTER_BILINEAR);

    uint64_t clayRequiredMemory = Clay_MinMemorySize();

    Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);
    Clay_SetCustomRenderCommandFunction(&MyCustomRenderCommand);

    Clay_Dimensions LastScreenSize;

    while (!WindowShouldClose()) {
        // Compute the layout        

        Clay_BeginLayout();


        Clay_RenderCommandArray renderCommandsTop = Clay_EndLayout();
        
        BeginDrawing();
            ClearBackground(BLACK);
            Clay_Raylib_Render(renderCommandsTop, fonts);
        EndDrawing();
    }

    Clay_Raylib_Close();
}