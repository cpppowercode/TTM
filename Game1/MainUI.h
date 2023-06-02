#pragma once
class MainUI : public Actor
{
public:
    static MainUI* Create(string name = "MainUI");
	class Player* player;
	class Cannon* cannon;

	bool Option;

	UI* open;
	UI* botton;
	UI* booster;
	UI* bomb;
	UI* gun;
	UI* reload;
	UI* bullet;
	UI* bullet2;
	UI* bullet3;
	UI* bullet4;
	UI* bullet5;
	UI* stop;
	UI* option;
	UI* continueUI;
	UI* retry;
	UI* gauge;
	UI* gaugefront;
	UI* gaugeback;

    MainUI();
    virtual ~MainUI();

    void Set() {}
    void Get() {}
public:
    void	Update() override;
    void	Render() override;
    void	Release() override;
	void	Hierarchy();
};