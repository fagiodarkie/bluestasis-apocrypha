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
        std::string id() const;
        std::string sound() const;

        option_iterator firstOption() const;
        option_iterator lastOption() const;
        option_iterator option(const std::string& option_key) const;

    protected:
        std::string _title, _text, _id, _soundfile;
        std::vector<option::Option> _options;
    };
}

#endif //BLUESTASIS_APOCRYPHA_SCREEN_H
