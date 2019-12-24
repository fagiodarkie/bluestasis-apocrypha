//
// Created by apteros on 20/12/2019.
//

#include "SaveEntry.h"

namespace gamesave::save {
    SaveEntry::SaveEntry(const std::string& name, unsigned long chapterId, const std::string& screenId)
        : _name(name), _chapterId(chapterId), _screenId(screenId) { }

    unsigned long SaveEntry::getChapter() const { return _chapterId; }
    std::string SaveEntry::getName() const { return _name; }
    std::string SaveEntry::getScreenKey() const { return _screenId; }

    void SaveEntry::updateChapter(unsigned long newChapter) { _chapterId = newChapter; }
    void SaveEntry::updateScreenKey(const std::string & newScreen) { _screenId = newScreen; }

    void SaveEntry::serialisation() {
        synch("name", _name);
        synch("chapterKey", _chapterId);
        synch("screenKey", _screenId);
    }

    void SaveEntry::operator=(const SaveEntry &other) {
        _name = other._name;
        _chapterId = other._chapterId;
        _screenId = other._screenId;
    }
}