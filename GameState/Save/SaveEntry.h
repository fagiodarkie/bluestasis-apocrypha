//
// Created by apteros on 20/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_SAVEENTRY_H
#define BLUESTASIS_APOCRYPHA_SAVEENTRY_H

#include <string>
#include "../../thirdparty/serialisable/serialisable.hpp"

namespace gamesave::save {
    class SaveEntry : public Serialisable {
    public:
        SaveEntry() {}
        SaveEntry(const std::string& name, unsigned long chapterId, const std::string& screenId);

        void serialisation() override;

        std::string getName() const;
        unsigned long getChapter() const;
        std::string getScreenKey() const;

        void operator=(const SaveEntry& other);

        void updateChapter(unsigned long newChapter);
        void updateScreenKey(const std::string& newScreen);

    private:
        std::string _name, _screenId;
        unsigned long _chapterId;
    };
}

#endif //BLUESTASIS_APOCRYPHA_SAVEENTRY_H
