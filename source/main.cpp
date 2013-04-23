#include <iostream>
#include <exception>

#include "Renderer.h"
#include "Player.h"
#include "Coordinates.h"

#include "Frame.h"
#include "Animation.h"
#include "Animator.h"
#include "AnimationManager.h"

int main()
{
    // Create scene
    sf::RenderWindow win(sf::VideoMode(1024, 768), "FlippyBox");
    Renderer renderer(win);

    // Load texture from image
    sf::Image CharacterImage;
    CharacterImage.loadFromFile("character.png");
    CharacterImage.createMaskFromColor(sf::Color::Black);
    sf::Texture CharacterAnim;
    CharacterAnim.loadFromImage(CharacterImage);

    sf::Texture CharacterSprite;
    CharacterSprite.loadFromImage(CharacterImage, sf::Rect<int>(0, 0, 48, 64));
    sf::Sprite playerSprite(CharacterSprite);

    // Create coordinates
    std::shared_ptr<Coordinates> my_coor(std::make_shared<Coordinates>(400, 300));

    // Create player
    std::shared_ptr<Player> my_player(std::make_shared<Player>(playerSprite, my_coor));

    // Add player to renderer
    renderer.add_drawable("Flippy", my_player);

    // delete player from renderer
    //renderer.delete_drawable("Flippy");

    // Define animations
    std::shared_ptr<Animation> GoUp = AnimationManager::Instance().get_animation("player_up");
    std::shared_ptr<Animation> GoRight = AnimationManager::Instance().get_animation("player_right");
    std::shared_ptr<Animation> GoDown = AnimationManager::Instance().get_animation("player_down");
    std::shared_ptr<Animation> GoLeft = AnimationManager::Instance().get_animation("player_left");

    // Create animator for player
    Animator animatorPlayer(my_player, GoUp, true, true, 0.3f);

    // Main loop
    sf::Clock clock_anim;
    while(win.isOpen())
    {
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && animatorPlayer.get_anim() != GoLeft)
            animatorPlayer.set_anim(GoLeft);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && animatorPlayer.get_anim() != GoRight)
            animatorPlayer.set_anim(GoRight);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && animatorPlayer.get_anim() != GoUp)
            animatorPlayer.set_anim(GoUp);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && animatorPlayer.get_anim() != GoDown)
            animatorPlayer.set_anim(GoDown);

        sf::Time elapsed = clock_anim.restart();
        animatorPlayer.anim(elapsed.asSeconds());

        renderer.update_position_sprites();
        renderer.draw_all();
    }
    return EXIT_SUCCESS;
}























//
///** We need this to easily convert between pixel and real-world coordinates*/
//static const float SCALE = 30.f;
//
///** Create the base for the boxes to land */
//void CreateGround(b2World& World, float X, float Y);
//
///** Create the boxes */
//void CreateBox(b2World& World, std::vector<sf::RectangleShape*> &tabBoxes, sf::RectangleShape &tempShape);
//
//int main()
//{
//    /** Prepare the window */
//    sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Test");
//    Window.setFramerateLimit(60);
//
//     /** Prepare boxes */
//    std::vector<sf::RectangleShape*> tabBoxes;
//    sf::RectangleShape tempShape(sf::Vector2f(32, 32));
//    tempShape.setFillColor(sf::Color(rand() % 255,rand() % 255,rand() % 255));
//    tempShape.setOutlineThickness(1);
//    tempShape.setOutlineColor(sf::Color(0,0,0));
//
//
//    /** Prepare the world */
//    b2Vec2 Gravity(0.f, 9.8f);
//    b2World World(Gravity);
//    CreateGround(World, 400.f, 500.f);
//
//    /** Prepare textures */
//    sf::Texture GroundTexture;
//    GroundTexture.loadFromFile("ground.png");
//
//    while (Window.isOpen())
//    {
//        // Traitement des events
//        sf::Event event;
//        while(Window.pollEvent(event))
//        {
//            switch(event.type)
//            {
//                case sf::Event::MouseButtonPressed :
//                    CreateBox(World, tabBoxes, tempShape);
//                    tempShape.setFillColor(sf::Color(rand() % 255,rand() % 255,rand() % 255));
//                    break;
//                case sf::Event::MouseMoved :
//                    tempShape.setPosition(sf::Mouse::getPosition(Window).x-(tempShape.getSize().x/2), sf::Mouse::getPosition(Window).y-tempShape.getSize().y/2); // Centre souris
//                    break;
//                case sf::Event::Closed :
//                    Window.close();
//                default:
//                    break;
//            }
//        }
//
//        // Gestion collisions
//        World.Step(1/60.f, 10, 6);
//
//        Window.clear(sf::Color::White);
//        Window.draw(tempShape);
//
//        int BodyCount = 0;
//        int i = 1;
//        for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
//        {
//            if (BodyIterator->GetType() == b2_dynamicBody)
//            {
//
//                tabBoxes[tabBoxes.size()-i]->setOrigin((tabBoxes[tabBoxes.size()-i]->getSize().x)/2, (tabBoxes[tabBoxes.size()-i]->getSize().y)/2);
//                tabBoxes[tabBoxes.size()-i]->setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
//                tabBoxes[tabBoxes.size()-i]->setRotation(BodyIterator->GetAngle() * 180/b2_pi);
//
//                Window.draw(*tabBoxes[tabBoxes.size()-i]);
//                ++BodyCount;
//                ++i;
//            }
//            else
//            {
//                sf::Sprite GroundSprite;
//                GroundSprite.setTexture(GroundTexture);
//                GroundSprite.setOrigin(400.f, 8.f);
//                GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
//                GroundSprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
//                Window.draw(GroundSprite);
//            }
//        }
//        Window.display();
//    }
//
//        return 0;
//}
//
//void CreateBox(b2World& World, std::vector<sf::RectangleShape*> &tabBoxes, sf::RectangleShape &tempShape)
//{
//    b2BodyDef BodyDef;
//    BodyDef.position = b2Vec2((tempShape.getPosition().x+tempShape.getSize().x/2)/SCALE, (tempShape.getPosition().y+tempShape.getSize().y/2)/SCALE); // Centre souris
//    BodyDef.type = b2_dynamicBody;
//    b2Body* Body = World.CreateBody(&BodyDef);
//
//    b2PolygonShape Shape;
//    Shape.SetAsBox((tempShape.getSize().x/2)/SCALE, (tempShape.getSize().y/2)/SCALE);
//    b2FixtureDef FixtureDef;
//    FixtureDef.density = 1.f;
//    FixtureDef.friction = 0.7f;
//    FixtureDef.restitution = 0.2f;
//    FixtureDef.shape = &Shape;
//    Body->CreateFixture(&FixtureDef);
//
//    sf::RectangleShape *Sprite;
//    Sprite = new sf::RectangleShape(sf::Vector2f(tempShape.getSize().x, tempShape.getSize().y));
//    Sprite->setPosition(tempShape.getPosition().x/SCALE, tempShape.getPosition().y/SCALE);
//    Sprite->setFillColor(tempShape.getFillColor());
//    Sprite->setOutlineThickness(tempShape.getOutlineThickness());
//    Sprite->setOutlineColor(tempShape.getOutlineColor());
//    tabBoxes.push_back(Sprite);
//    std::cout << tabBoxes.size() << std::endl;
//}
//
//void CreateGround(b2World& World, float X, float Y)
//{
//    b2BodyDef BodyDef;
//    BodyDef.position = b2Vec2(X/SCALE, Y/SCALE);
//    BodyDef.type = b2_staticBody;
//    b2Body* Body = World.CreateBody(&BodyDef);
//
//    b2PolygonShape Shape;
//    Shape.SetAsBox((800.f/2)/SCALE, (16.f/2)/SCALE);
//    b2FixtureDef FixtureDef;
//    FixtureDef.density = 0.f;
//    FixtureDef.shape = &Shape;
//    Body->CreateFixture(&FixtureDef);
//}
