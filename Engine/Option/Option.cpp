//
// Created by apteros on 12/12/2019.
//

#include "Option.h"

namespace engine::option
{
    void Option::serialisation() {
        synch("optionId", _option_id);
        synch("endScreenId", _end_screen_id);
        synch("optionKey", _option_key);
        synch("optionText", _option_text);
    }

    char Option::key() const {
        return _option_key;
    }

    unsigned long Option::id() const {
        return _option_id;
    }

    std::string Option::text() const {
        return _option_text;
    }

    unsigned long Option::endScreen() const {
        return _end_screen_id;
    }

}