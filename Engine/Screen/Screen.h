//
// Created by apteros on 12/12/2019.
//

#ifndef BLUESTASIS_APOCRYPHA_SCREEN_H
#define BLUESTASIS_APOCRYPHA_SCREEN_H

#include "../../thirdparty/serialisable/serialisable.hpp"
#include "../Option/Option.h"
#include <string>

namespace engine::screen
{
    class Screen : public Serialisable {
    public:
        typedef std::vector<option::Option>::const_iterator option_iterator;
        virtual void serialisation() override ;

        std::string title() const;
        std::string text() const;
        unsigned long id() const;

        option_iterator firstOption() const;
        option_iterator lastOption() const;

    protected:
        std::string _title, _text;
        unsigned long _id;
        std::vector<option::Option> _options;
    };
}

#endif //BLUESTASIS_APOCRYPHA_SCREEN_H
