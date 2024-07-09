#define OLC_PGE_APPLICATION
#define OLC_GFX_OPENGL33
#include "olcPixelGameEngine.h"

#define OLC_PGEX_TINYGUI
#include "olcPGEX_TinyGUI.h"

const std::string loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam nec purus ac libero ultricies ultricies. Sed nec nunc nec libero ultricies ultricies. Nullam nec purus ac libero ultricies ultricies. Nullam nec purus ac libero test ultricies.";

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name your application
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		gui.baseColor = olc::Pixel(255, 255, 255);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(gui.PixelBrightness(gui.baseColor, 0.8f));

		gui.AddDockingAreaRight("toolbox", 200);

		gui.PushRect(gui.PeekRect().Expand(-5));
		gui.PushRect(gui.RectCutLeft(120));

		// Button
		if (gui.Button("btn1", gui.RectCutTop(22), "Button 1")) {
			gui.ShowPopup("popup1");
		}

		// Toggle
		static bool tgl1 = false;
		if (gui.Toggle("tgl1", gui.RectCutTop(22), "Toggle 1", tgl1)) {

		}

		gui.PopRect();

		gui.RectCutLeft(10);

		gui.PushRect(gui.RectCutLeft(140));

		// Slider
		static float sld1 = 0.0f;
		gui.SliderF("sld1", gui.RectCutTop(22), sld1, 0.0f, 1.0f, 0.01f);
		gui.PopRect();

		gui.RectCutLeft(10);

		// Spinner + EditBox
		static int spn1 = 0;
		gui.PushRect(gui.RectCutLeft(140));

		gui.Spinner("spn1", gui.RectCutTop(22), spn1, 0, 100, 1);

		gui.RectCutTop(5);

		static std::string editValue1 = "Edit me!";
		gui.EditBox("edt1", gui.RectCutTop(22), editValue1);

		gui.PopRect();

		gui.PopRect();

		std::string tabs[] = { "Tab 1", "Tab 2", "Tab 3", "Tab Long 5", "Tab Long 6" };

		// Frame
		gui.BeginFrame("frame1", "Frame Test", { 20, 120 }, 200, true);
		gui.TabBar("tab1", gui.RectCutTop(25), tabs, 5, selTab);

		gui.RectCutTop(3);

		if (selTab == 0) gui.Button("btn2", gui.RectCutTop(22), "Button 2");
		else if (selTab == 1) gui.Toggle("tgl2", gui.RectCutTop(22), "Toggle 2", tgl1);
		else if (selTab == 2) gui.SliderF("sld2", gui.RectCutTop(22), sld1, 0.0f, 1.0f, 0.01f);
		
		gui.EndFrame();

		gui.BeginFrame("frame2", "Label Test", { 250, 120 }, 220);
		gui.Label(gui.RectCutTop(100), loremIpsum, AlignCenter | AlignMiddle, std::nullopt, true);
		gui.EndFrame();

		gui.BeginFrame("guicolor", "GUI Base Color", { 12, ScreenHeight() - 150 }, 240, true);
		
		gui.PushRect(gui.RectCutTop(22));
		if (gui.Spinner("s_col_red", gui.RectCutRight(80), guiRGB[0], 0, 255, 1, "R:%d")) {
			gui.baseColor.r = uint8_t(guiRGB[0] & 0xFF);
		}
		gui.RectCutRight(3);
		if (gui.Slider("col_red", gui.PeekRect(), guiRGB[0], 0, 255, 1, olc::RED)) {
			gui.baseColor.r = uint8_t(guiRGB[0] & 0xFF);
		}
		gui.PopRect();

		gui.RectCutTop(5);

		gui.PushRect(gui.RectCutTop(22));
		if (gui.Spinner("s_col_green", gui.RectCutRight(80), guiRGB[1], 0, 255, 1, "G:%d")) {
			gui.baseColor.g = uint8_t(guiRGB[1] & 0xFF);
		}
		gui.RectCutRight(3);
		if (gui.Slider("col_green", gui.PeekRect(), guiRGB[1], 0, 255, 1, olc::GREEN)) {
			gui.baseColor.g = uint8_t(guiRGB[1] & 0xFF);
		}
		gui.PopRect();

		gui.RectCutTop(5);

		gui.PushRect(gui.RectCutTop(22));
		if (gui.Spinner("s_col_blue", gui.RectCutRight(80), guiRGB[2], 0, 255, 1, "B:%d")) {
			gui.baseColor.b = uint8_t(guiRGB[2] & 0xFF);
		}
		gui.RectCutRight(3);
		if (gui.Slider("col_blue", gui.PeekRect(), guiRGB[2], 0, 255, 1, olc::BLUE)) {
			gui.baseColor.b = uint8_t(guiRGB[2] & 0xFF);
		}
		gui.PopRect();

		gui.EndFrame();

		std::string menuItems[] = {
			"Menu Item 1",
			"Menu Item 2",
			"Menu Item 3",
			"Menu Item 4",
			"---",
			"Menu Item 5"
		};
		gui.MakePopup("popup1", menuItems, 6);

		return true;
	}

	olcPGEX_TinyGUI gui;
	size_t selTab{ 0 };
	int guiRGB[3]{ 255, 255, 255 };
};

int main()
{
	Example demo;
	if (demo.Construct(800, 600, 1, 1))
		demo.Start();
	return 0;
}
