//
// Created by apteros on 12/12/2019.
//

#include "Chapter.h"

namespace engine::chapter {
    void Chapter::serialisation() {
        synch("chapter", _chapterId);
        synch("schemaVersion", _chapterSchema);
        synch("screens", _screens);
    }

    unsigned long Chapter::chapterNumber() const {
        return _chapterId;
    }

    Chapter::screenIterator Chapter::firstScreen() const {
        return _screens.cbegin();
    }
}