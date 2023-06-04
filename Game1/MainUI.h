#pragma once
struct Long4
{
	long a;
	long b;
	long c;
	long d;

	Long4() {};

	Long4(long a, long b, long c, long d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	Long4 operator =(Long4 a)
	{
		this->a = a.a;
		this->b = a.b;
		this->c = a.c;
		this->d = a.d;

		return *this;
	}
};
class MainUI : public Actor
{
public:
    static MainUI* Create(string name = "MainUI");
	class Player* player;
	class Cannon* cannon;

	//int a[4];
	

	Actor* plane;
	Actor* plane2;
	Actor* plane3;
	Actor* plane4;
	Actor* plane5;
	Actor* plane6;
	Actor* plane7;
	Actor* plane8;
	Actor* plane9;
	Camera* Cam;

	Actor* sky;
	Actor* sky2;
	Actor* sky3;

	int count;
	float time;
	float time2;
	bool Option;
	bool Booster;

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
	UI* mouse;
	UI* bell;

    MainUI();
    virtual ~MainUI();

    void Set() {}
    void Get() {}
public:
    void	Update() override;
	void	LateUpdate();
    void	Render() override;
    void	Release() override;
	void	Hierarchy();
};