//
// Created by apteros on 12/12/2019.
//

#include "Option.h"

namespace engine::option
{
    void Option::serialisation() {
        synch("target", _end_screen_id);
        synch("key", _option_key);
        synch("text", _option_text);
    }

    std::string Option::key() const {
        return _option_key;
    }

    std::string Option::text() const {
        return _option_text;
    }

    std::string Option::endScreen() const {
        return _end_screen_id;
    }

}