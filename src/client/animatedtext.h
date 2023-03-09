
#ifndef ANIMATEDTEXT_H
#define ANIMATEDTEXT_H

#include "thing.h"
#include <framework/graphics/fontmanager.h>
#include <framework/core/timer.h>
#include <framework/graphics/cachedtext.h>

// @bindclass
class AnimatedText : public Thing
{
public:
    AnimatedText();

    void drawText(const Point& dest, const Rect& visibleRect);

    void setColor(int color);
    void setText(const std::string& text);
    void setOffset(const Point& offset) { m_offset = offset; }
    void setFont(const std::string& fontName);

    Color getColor() { return m_color; }
    const CachedText& getCachedText() const { return m_cachedText; }
    Point getOffset() { return m_offset; }
    Timer getTimer() { return m_animationTimer; }

    bool merge(const AnimatedTextPtr& other);

    AnimatedTextPtr asAnimatedText() { return static_self_cast<AnimatedText>(); }
    bool isAnimatedText() { return true; }
    std::string getText() { return m_cachedText.getText(); }

protected:
    virtual void onAppear();

private:
    Color m_color;
    Timer m_animationTimer;
    CachedText m_cachedText;
    Point m_offset;
};

#endif
