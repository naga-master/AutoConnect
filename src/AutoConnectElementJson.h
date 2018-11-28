/**
 * Declaration of AutoConnectElement extended classes using JSON.
 * @file AutoConnectElementJson.h
 * @author hieromon@gmail.com
 * @version  0.9.7
 * @date 2018-11-17
 * @copyright  MIT license.
 */

#ifndef _AUTOCONNECTELEMENTJSON_H_
#define _AUTOCONNECTELEMENTJSON_H_

#include "AutoConnectElementBasis.h"
#include <ArduinoJson.h>

#define AUTOCONNECT_JSON_KEY_ACTION      "action"
#define AUTOCONNECT_JSON_KEY_ARRANGE     "arrange"
#define AUTOCONNECT_JSON_KEY_CHECKED     "checked"
#define AUTOCONNECT_JSON_KEY_ELEMENT     "element"
#define AUTOCONNECT_JSON_KEY_HORIZONTAL  "horizontal"
#define AUTOCONNECT_JSON_KEY_LABEL       "label"
#define AUTOCONNECT_JSON_KEY_MENU        "menu"
#define AUTOCONNECT_JSON_KEY_NAME        "name"
#define AUTOCONNECT_JSON_KEY_OPTION      "option"
#define AUTOCONNECT_JSON_KEY_STYLE       "style"
#define AUTOCONNECT_JSON_KEY_TITLE       "title"
#define AUTOCONNECT_JSON_KEY_TYPE        "type"
#define AUTOCONNECT_JSON_KEY_URI         "uri"
#define AUTOCONNECT_JSON_KEY_VALUE       "value"
#define AUTOCONNECT_JSON_KEY_VERTICAL    "vertical"
#define AUTOCONNECT_JSON_TYPE_ACBUTTON   "ACButton"
#define AUTOCONNECT_JSON_TYPE_ACCHECKBOX "ACCheckBox"
#define AUTOCONNECT_JSON_TYPE_ACELEMENT  "ACElement"
#define AUTOCONNECT_JSON_TYPE_ACINPUT    "ACInput"
#define AUTOCONNECT_JSON_TYPE_ACRADIO    "ACRadio"
#define AUTOCONNECT_JSON_TYPE_ACSELECT   "ACSelect"
#define AUTOCONNECT_JSON_TYPE_ACSUBMIT   "ACSubmit"
#define AUTOCONNECT_JSON_TYPE_ACTEXT     "ACText"

/**
 * AutoConnectAux element base with handling with JSON object.
 * Placed a raw text that can be added by user sketch.
 * @param  name     A name string for the element.
 * @param  value    A raw text to be placed in HTML.
 */
class AutoConnectElementJson : virtual public AutoConnectElementBasis {
 public:
  explicit AutoConnectElementJson(const char* name = "", const char* value = "") {
    AutoConnectElementBasis::name = name;
    AutoConnectElementBasis::value = value;
  }
  ~AutoConnectElementJson() {}
  virtual bool  loadElement(const JsonObject& json);

 protected:
  void  _setElement(const JsonObject& json);
};

/**
 * Button arrangement class, a part of AutoConnectAux element with
 * handling JSON object.
 * Place a labeled button that can be added by user sketch.
 * @param  name     Button element name string.
 * @param  value    Value string with the placed button.
 * @param  action   Script code to execute with the button pushed.
 */
class AutoConnectButtonJson : public AutoConnectElementJson, public AutoConnectButtonBasis {
 public:
  explicit AutoConnectButtonJson(const char* name = "", const char* value = "", const String action = String()) {
    AutoConnectButtonBasis::name = name;
    AutoConnectButtonBasis::value = value;
    AutoConnectButtonBasis::action = action;
  }
  ~AutoConnectButtonJson() {}
  bool  loadElement(const JsonObject& json);
};

/**
 * Checkbox arrangement class, a part of AutoConnectAux element with
 * handling JSON object.
 * Place a optionally labeled input-box that can be added by user sketch.
 * @param  name     Checkbox name string.
 * @param  value    A string value associated with the input.
 * @param  label    A label string that follows checkbox, optionally.
 * The label is placed on the right side of the checkbox.
 */
class AutoConnectCheckboxJson : public AutoConnectElementJson, public AutoConnectCheckboxBasis {
 public:
  explicit AutoConnectCheckboxJson(const char* name = "", const char* value = "", const char* label = "", const bool checked = false) {
    AutoConnectCheckboxBasis::name = name;
    AutoConnectCheckboxBasis::value = value;
    AutoConnectCheckboxBasis::label = label;
    AutoConnectCheckboxBasis::checked = checked;
  }
  ~AutoConnectCheckboxJson() {}
  bool  loadElement(const JsonObject& json);
};

/**
 * Input-box arrangement class, a part of AutoConnectAux element with
 * handling JSON object.
 * Place a optionally labeled input-box that can be added by user sketch.
 * @param  name     Input-box name string.
 * @param  value    Default value string. This string display as a placeholder by the default.
 * @param  label    A label string that follows Input-box, optionally.
 * The label is placed in front of Input-box.
 */
class AutoConnectInputJson : public AutoConnectElementJson, public AutoConnectInputBasis {
 public:
  explicit AutoConnectInputJson(const char* name = "", const char* value = "", const char* label = "") {
    AutoConnectInputBasis::name = name;
    AutoConnectInputBasis::value = value;
    AutoConnectInputBasis::label = label;
  }
  ~AutoConnectInputJson() {}
  bool  loadElement(const JsonObject& json);
};

/**
* Radio-button arrangement class, a part of AutoConnectAux element.
* Place a group of radio-button items and selectable mark checked.
* @param  name     Radio-button name string.
* @param  options  Array of value collection.
* @param  label    A label string that follows radio-buttons group.
* @param  checked  Index of check marked item.
*/
class AutoConnectRadioJson : public AutoConnectElementJson, public AutoConnectRadioBasis {
 public:
  explicit AutoConnectRadioJson(const char* name = "", std::vector<String> values = {}, const char* label = "", const ACArrange_t order = AC_Vertical, const uint8_t checked = 0) {
    AutoConnectRadioBasis::name = name;
    AutoConnectRadioBasis::_values = values;
    AutoConnectRadioBasis::label = label;
    AutoConnectRadioBasis::order = order;
    AutoConnectRadioBasis::checked = checked;
  }
  ~AutoConnectRadioJson() {}
  bool loadElement(const JsonObject& json);
};

/**
 * Selection-box arrangement class, A part of AutoConnectAux element.
 * Place a optionally labeled Selection-box that can be added by user sketch.
 * @param  name     Input-box name string.
 * @param  options  String array display in a selection list.
 * @param  label    A label string that follows Input-box, optionally.
 * The label is placed in front of Input-box.
 */
class AutoConnectSelectJson : public AutoConnectElementJson, public AutoConnectSelectBasis {
 public:
  explicit AutoConnectSelectJson(const char* name = "", std::vector<String> options = {}, const char* label = "") {
    AutoConnectSelectBasis::name = name;
    AutoConnectSelectBasis::_options = options;
    AutoConnectSelectBasis::label = label;
  }
  ~AutoConnectSelectJson() {}
  bool  loadElement(const JsonObject& json);
};

/**
 * Submit button arrangement class, a part of AutoConnectAux element.
 * Place a submit button with a label that can be added by user sketch.
 * With the button behavior, the values of the elements contained in
 * the form would be sent using the post method.
 * @param  name  Button name string.
 * @param  value Sending value string.
 * @param  uri   Sending uri string.
 */
class AutoConnectSubmitJson : public AutoConnectElementJson, public AutoConnectSubmitBasis {
 public:
  explicit AutoConnectSubmitJson(const char* name = "", const char* value = "", const char* uri = "") {
    AutoConnectSubmitBasis::name = name;
    AutoConnectSubmitBasis::value = value;
    AutoConnectSubmitBasis::uri = uri;
  }
  ~AutoConnectSubmitJson() {}
  bool  loadElement(const JsonObject& json);
};

/**
 * Text arrangement class, a part of AutoConnectAux element.
 * @param
 * @param  name     Text name string.
 * @param  value    Text value string.
 * @param  style    A string of style-code for decoration, optionally.
 * An arrangement text would be placed with <div> contains. A string
 * of style-codes are given for '<div style=>'.
 */
class AutoConnectTextJson : public AutoConnectElementJson, public AutoConnectTextBasis {
 public:
  explicit AutoConnectTextJson(const char* name = "", const char* value = "", const char* style = "") {
    AutoConnectTextBasis::name = name;
    AutoConnectTextBasis::value = value;
    AutoConnectTextBasis::style = style;
  }
  ~AutoConnectTextJson() {}
  bool  loadElement(const JsonObject& json);
};

#endif // _AUTOCONNECTELEMENTJSON_H_
