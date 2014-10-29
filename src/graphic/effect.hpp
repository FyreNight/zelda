#pragma once

class Drawable;
class Effect {
public:
    Effect(Drawable* drawable);
    Effect(Drawable* drawable, Effect* next);

    Effect* next() const;

    virtual bool IsFinished() const = 0;

    virtual void Tick(double delta) = 0;
    virtual void Render() const = 0;

    virtual void Leave();

protected:
    Drawable* drawable_;
    Effect* next_;
};
