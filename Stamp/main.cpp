// SFML includes
#include <SFML/Graphics.hpp>

using namespace sf;

// STL includes
#include <vector>

using namespace std;

int main()
{
	vector<VideoMode> videoModes = VideoMode::getFullscreenModes();
	VideoMode videoMode = (videoModes.size() != 0) ? videoModes.front() : VideoMode::getDesktopMode();

	RenderWindow window(videoMode, "Stamp!", Style::Default);
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	
	while (window.isOpen())
	{
		// Game Loop:
		// -> log events to event manager
		// -> process game logic, request assets to render manager
		// -> offload render manager to draw assets
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}