#include "FighterFactory.h"

//level1
shared_ptr<Entity> FighterFactory::newPlayer(shared_ptr<Entity> p, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity>target, Level1Scene* sc)
{
	if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
			cerr << "Failed to load spritesheet!" << std::endl;
		}
		auto rect = IntRect(32, 0, 32, 32);
		p = sc->makeEntity();
		p->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
		//add sprites
		auto s = p->addComponent<ShapeComponent>();
		//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
		s->setShape<sf::RectangleShape>(size);
		s->getShape().setFillColor(Color::Magenta);
		s->getShape().setOrigin(size.x / 2, size.y / 2);
		//add movement
		p->addComponent<ActorMovementComponent>();



		//bar to show HP
		hpBar = sc->makeEntity();
		auto hp = hpBar->addComponent<ShapeComponent>();

		//add HP
		p->addComponent<HitPointsComponent>(100);
		p->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(hpBar, Color::Green);

		//set enemy as target of attacks
		p->addComponent<AttackComponent>(target);

		return p;
}

shared_ptr<Entity> FighterFactory::newEnemy(shared_ptr<Entity> e, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity>target, Level1Scene* sc)
{
	if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	auto rect = IntRect(32, 0, 32, 32);
	e = sc->makeEntity();
	e->setPosition(ls::getTilePosition(ls::findTiles(ls::END)[0]));
	//add sprites
	auto s = e->addComponent<ShapeComponent>();
	//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
	s->setShape<sf::RectangleShape>(size);
	s->getShape().setFillColor(Color::Yellow);
	s->getShape().setOrigin(size.x / 2, size.y / 2);
	//add movement
	e->addComponent<ActorMovementComponent>();



	//bar to show HP
	hpBar = sc->makeEntity();
	auto hp = hpBar->addComponent<ShapeComponent>();

	//add HP
	e->addComponent<HitPointsComponent>(100);
	e->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(hpBar, Color::Red);

	//set enemy as target of attacks
	e->addComponent<AttackComponent>(target);

	return e;
}



//level2
shared_ptr<Entity> FighterFactory::newPlayer(shared_ptr<Entity> p, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity>target, Level2Scene* sc)
{
	if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	auto rect = IntRect(32, 0, 32, 32);
	p = sc->makeEntity();
	p->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
	//add sprites
	auto s = p->addComponent<ShapeComponent>();
	//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
	s->setShape<sf::RectangleShape>(size);
	s->getShape().setFillColor(Color::Magenta);
	s->getShape().setOrigin(size.x / 2, size.y / 2);
	//add movement
	p->addComponent<ActorMovementComponent>();



	//bar to show HP
	hpBar = sc->makeEntity();
	auto hp = hpBar->addComponent<ShapeComponent>();

	//add HP
	p->addComponent<HitPointsComponent>(100);
	p->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(hpBar, Color::Green);

	//set enemy as target of attacks
	p->addComponent<AttackComponent>(target);

	return p;
}

shared_ptr<Entity> FighterFactory::newEnemy(shared_ptr<Entity> e, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity>target, Level2Scene* sc)
{
	if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	auto rect = IntRect(32, 0, 32, 32);
	e = sc->makeEntity();
	e->setPosition(ls::getTilePosition(ls::findTiles(ls::END)[0]));
	//add sprites
	auto s = e->addComponent<ShapeComponent>();
	//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
	s->setShape<sf::RectangleShape>(size);
	s->getShape().setFillColor(Color::Yellow);
	s->getShape().setOrigin(size.x / 2, size.y / 2);
	//add movement
	e->addComponent<ActorMovementComponent>();



	//bar to show HP
	hpBar = sc->makeEntity();
	auto hp = hpBar->addComponent<ShapeComponent>();

	//add HP
	e->addComponent<HitPointsComponent>(100);
	e->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(hpBar, Color::Red);

	//set enemy as target of attacks
	e->addComponent<AttackComponent>(target);

	return e;
}



//level3

shared_ptr<Entity> FighterFactory::newPlayer(shared_ptr<Entity> p, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity>target, Level3Scene* sc)
{
	if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	auto rect = IntRect(32, 0, 32, 32);
	p = sc->makeEntity();
	p->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
	//add sprites
	auto s = p->addComponent<ShapeComponent>();
	//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
	s->setShape<sf::RectangleShape>(size);
	s->getShape().setFillColor(Color::Magenta);
	s->getShape().setOrigin(size.x / 2, size.y / 2);
	//add movement
	p->addComponent<ActorMovementComponent>();



	//bar to show HP
	hpBar = sc->makeEntity();
	auto hp = hpBar->addComponent<ShapeComponent>();

	//add HP
	p->addComponent<HitPointsComponent>(100);
	p->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(hpBar, Color::Green);

	//set enemy as target of attacks
	p->addComponent<AttackComponent>(target);

	return p;
}

shared_ptr<Entity> FighterFactory::newEnemy(shared_ptr<Entity> e, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity>target, Level3Scene* sc)
{
	if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	auto rect = IntRect(32, 0, 32, 32);
	e = sc->makeEntity();
	e->setPosition(ls::getTilePosition(ls::findTiles(ls::END)[0]));
	//add sprites
	auto s = e->addComponent<ShapeComponent>();
	//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
	s->setShape<sf::RectangleShape>(size);
	s->getShape().setFillColor(Color::Yellow);
	s->getShape().setOrigin(size.x / 2, size.y / 2);
	//add movement
	e->addComponent<ActorMovementComponent>();



	//bar to show HP
	hpBar = sc->makeEntity();
	auto hp = hpBar->addComponent<ShapeComponent>();

	//add HP
	e->addComponent<HitPointsComponent>(100);
	e->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(hpBar, Color::Red);

	//set enemy as target of attacks
	e->addComponent<AttackComponent>(target);

	return e;
}