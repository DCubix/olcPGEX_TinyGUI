//#define OLC_PGE_APPLICATION
//#define OLC_GFX_OPENGL33
//#include "olcPixelGameEngine.h"

#define TINYGUI_IMPLEMENTATION
#include "olcPGEX_TinyGUI.h"

#define SMOL_FRAME_IMPLEMENTATION
#include "smol_frame.h"

#define SMOL_UTILS_IMPLEMENTATION
#include "smol_utils.h"

const std::string loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam nec purus ac libero ultricies ultricies. Sed nec nunc nec libero ultricies ultricies. Nullam nec purus ac libero ultricies ultricies. Nullam nec purus ac libero test ultricies.";

class AppAdapter {
public:

	bool OnUserCreate() {
		gui.baseColor = Color{ 255, 255, 255, 255 };

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) {
		// TODO: Clear(gui.PixelBrightness(gui.baseColor, 0.8f));

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

		gui.BeginFrame("guicolor", "GUI Base Color", { 12, int(gui.GetRenderer().GetScreenSize().y) - 150}, 240, true);

		gui.PushRect(gui.RectCutTop(22));
		if (gui.Spinner("s_col_red", gui.RectCutRight(80), guiRGB[0], 0, 255, 1, "R:%d")) {
			gui.baseColor.r = uint8_t(guiRGB[0] & 0xFF);
		}
		gui.RectCutRight(3);
		if (gui.Slider("col_red", gui.PeekRect(), guiRGB[0], 0, 255, 1, Color{ 255, 0, 0, 255 })) {
			gui.baseColor.r = uint8_t(guiRGB[0] & 0xFF);
		}
		gui.PopRect();

		gui.RectCutTop(5);

		gui.PushRect(gui.RectCutTop(22));
		if (gui.Spinner("s_col_green", gui.RectCutRight(80), guiRGB[1], 0, 255, 1, "G:%d")) {
			gui.baseColor.g = uint8_t(guiRGB[1] & 0xFF);
		}
		gui.RectCutRight(3);
		if (gui.Slider("col_green", gui.PeekRect(), guiRGB[1], 0, 255, 1, Color{ 0, 255, 0, 255 })) {
			gui.baseColor.g = uint8_t(guiRGB[1] & 0xFF);
		}
		gui.PopRect();

		gui.RectCutTop(5);

		gui.PushRect(gui.RectCutTop(22));
		if (gui.Spinner("s_col_blue", gui.RectCutRight(80), guiRGB[2], 0, 255, 1, "B:%d")) {
			gui.baseColor.b = uint8_t(guiRGB[2] & 0xFF);
		}
		gui.RectCutRight(3);
		if (gui.Slider("col_blue", gui.PeekRect(), guiRGB[2], 0, 255, 1, Color{ 0, 0, 255, 255 })) {
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

	TinyGUI gui;
	size_t selTab{ 0 };
	int guiRGB[3]{ 255, 255, 255 };
};

#if 0
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
		app = std::make_unique<AppAdapter>();
		return app->OnUserCreate();
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		return app->OnUserUpdate(fElapsedTime);
	}

	std::unique_ptr<AppAdapter> app;
};

int main()
{
	Example demo;
	if (demo.Construct(800, 600, 1, 1))
		demo.Start();
	return 0;
}
#else
int main(int argc, char** argv) {
	glbInit(NULL, NULL);

	smol_frame_gl_spec_t spec = smol_init_gl_spec(4, 6, SMOL_TRUE, SMOL_TRUE, 0, 0);

	smol_frame_config_t conf{};
	conf.width = 1280;
	conf.height = 720;
	conf.title = "Smol Frame Example";
	conf.gl_spec = &spec;

	smol_frame_t* frame = smol_frame_create_advanced(&conf);

	glViewport(0, 0, conf.width, conf.height);

	AppAdapter app{};

	app.gui.GetRenderer().SetScreenSize({ uint32_t(conf.width), uint32_t(conf.height) });

	app.gui.OnCreate();
	app.OnUserCreate();

	constexpr double timeStep = 1.0 / 60.0;

	double lastTime = smol_timer();
	double accumulator = 0.0;

	while (!smol_frame_is_closed(frame)) {
		double currentTime = smol_timer();
		double deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		accumulator += deltaTime;

		smol_frame_update(frame);

		SMOL_FRAME_EVENT_LOOP(frame, ev) {
			
		}

		while (accumulator >= timeStep) {
			accumulator -= timeStep;
		}

		glClearColor(0.0f, 0.1f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		app.gui.OnUpdate(timeStep);
		app.OnUserUpdate(timeStep);
		app.gui.OnFinalize(timeStep);

		smol_frame_gl_swap_buffers(frame);
	}

	glbUninit();
	smol_frame_destroy(frame);

	return 0;
}
#endif
