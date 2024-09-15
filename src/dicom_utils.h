#ifndef DICOM_UTILS_H
#define DICOM_UTILS_H

#include <dcmtk/dcmdata/dcmfileformat.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <dcmtk/dcmimgcmp/dcmimagecompare.h>
#include <string>

bool readDicomTag(const std::string& filename, const std::string& tag);
bool readPixelData(const std::string& filename);
bool saveDicom(const std::string& filename, const std::string& outputFilename);
bool saveBitmap(const std::string& filename, const std::string& bitmapFilename);

#endif // DICOM_UTILS_H
