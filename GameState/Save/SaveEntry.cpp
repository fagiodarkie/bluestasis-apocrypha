//
// Created by apteros on 20/12/2019.
//

#include "SaveEntry.h"

namespace gamesave::save {
    SaveEntry::SaveEntry(std::string &name, std::string &chapterId, std::string &screenId)
        : _name(name), _chapterId(chapterId), _screenId(screenId) { }

    std::string SaveEntry::getChapter() const { return _chapterId; }
    std::string SaveEntry::getName() const { return _name; }
    std::string SaveEntry::getScreenKey() const { return _screenId; }

    void SaveEntry::updateChapter(const std::string & newChapter) { _chapterId = newChapter; }
    void SaveEntry::updateScreenKey(const std::string & newScreen) { _screenId = newScreen; }

    void SaveEntry::serialisation() {
        synch("name", _name);
        synch("chapterKey", _chapterId);
        synch("screenKey", _screenId);
    }
}