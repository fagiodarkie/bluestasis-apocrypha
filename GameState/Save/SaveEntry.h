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
        SaveEntry(std::string& name, std::string& chapterId, std::string& screenId);

        void serialisation() override;

        std::string getName() const;
        std::string getChapter() const;
        std::string getScreenKey() const;

        void updateChapter(const std::string& newChapter);
        void updateScreenKey(const std::string& newScreen);

    private:
        std::string _name, _chapterId, _screenId;
    };
}

#endif //BLUESTASIS_APOCRYPHA_SAVEENTRY_H
