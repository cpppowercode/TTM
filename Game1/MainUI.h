#pragma once
class MainUI : public Actor
{
public:
    static MainUI* Create(string name = "MainUI");
    MainUI();
    virtual ~MainUI();

    void Set() {}
    void Get() {}
public:
    void	Update() override;
    void	Release() override;

};