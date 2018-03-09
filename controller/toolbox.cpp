#include "toolbox.h"

toolbox::toolbox()
{

}


QString toolbox::capitalize(const QString &str)
{
      QString tmp = str;
      tmp = tmp.toLower();
      tmp[0] = str[0].toUpper();
      return tmp;
}
