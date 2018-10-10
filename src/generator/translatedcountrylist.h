/*
 * Copyright (c) 2018 Sune Vuorela <sune@vuorela.dk>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
#include <QHash>
#include <QString>
class QIODevice;

namespace TranslatedCountries {
    using TranslationCountryMap = QHash<QString,QString>;
    /**
     * \param device open QIODevice to read cldr xml data from
     * \return map of translation name => country id
     */
    TranslationCountryMap parseFile(QIODevice *device);
    /**
     * \param filePath path to read cldr xml file
     * \return map of translation name => country id
     */
    TranslationCountryMap parseFilePath(const QString &filePath);
    /**
     * \param directoryPath directory path to scan recursively for cldr xml files
     * On Debian systems, /usr/share/unicode/cldr/common/main is a good value for this.
     * \return map of translation name => country id
     */
    TranslationCountryMap parseFilesRecursive(const QString &directoryPath);}