#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QString>

class toolbox
{
public:
    /**
     * @brief toolbox constructor
     */
    toolbox();

    /* Methods ----------------------------------------------------*/
    /**
     * @brief capitalize
     * @param str The string to capitalize
     * @return The string capitalized
     */
    static QString capitalize(const QString &str);
};

#endif // TOOLBOX_H
