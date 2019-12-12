//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_OPTION_H
#define BLUESTASIS_APOCRYPHA_OPTION_H

#include "../../thirdparty/serialisable/serialisable.hpp"
#include <string>

namespace engine::option
{
    class Option : public Serialisable {
    public:
        virtual void serialisation() override;

        char key() const;
        unsigned long id() const;
        std::string text() const;
        unsigned long endScreen() const;

    protected:
        char _option_key;
        unsigned long _end_screen_id, _option_id;
        std::string _option_text;
    };
}


#endif //BLUESTASIS_APOCRYPHA_OPTION_H
