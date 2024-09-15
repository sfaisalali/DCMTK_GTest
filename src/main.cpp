#include <iostream>
#include "dicom_utils.h"

int main() {
    std::string dicomFile = "data/sample.dcm";
    std::string tag = "00100020"; // Example DICOM tag (Patient ID)

    // Read DICOM tag
    readDicomTag(dicomFile, tag);

    // Read pixel data
    readPixelData(dicomFile);

    // Save DICOM file
    saveDicom(dicomFile, "data/output.dcm");

    // Save bitmap file
    saveBitmap(dicomFile, "data/output.bmp");

    return 0;
}
