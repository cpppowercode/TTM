#pragma once
class Player : public Actor
{
public:
	static Player* Create(string name = "Player");
    Player();
    virtual ~Player();

    void Set() {}
    void Get() {}
public:
    void	Update() override;
    void	Release() override;

};

