//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_CHAPTER_H
#define BLUESTASIS_APOCRYPHA_CHAPTER_H

#include "../../thirdparty/serialisable/serialisable.hpp"
#include "../Screen/Screen.h"

namespace engine::chapter {
    class Chapter : public Serialisable {
    public:
        typedef std::vector<screen::Screen>::const_iterator screenIterator;
        virtual void serialisation() override;

        unsigned long chapterNumber() const;
        screenIterator firstScreen() const;
        screenIterator screen(const std::string& screenId) const;

        unsigned long id() const { return _chapterId; }

    protected:
        int _chapterSchema;
        unsigned long _chapterId;
        std::vector<screen::Screen> _screens;
    };
}


#endif //BLUESTASIS_APOCRYPHA_CHAPTER_H
