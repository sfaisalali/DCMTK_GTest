#include "dicom_utils.h"
#include <iostream>

bool readDicomTag(const std::string& filename, const std::string& tag) {
    DcmFileFormat fileformat;
    if (fileformat.loadFile(filename.c_str()).bad()) {
        std::cerr << "Failed to load DICOM file: " << filename << std::endl;
        return false;
    }
    DcmDataset *dataset = fileformat.getDataset();
    DcmTagKey tagKey(stoi(tag, nullptr, 16));
    OFString value;
    if (dataset->findAndGetOFString(tagKey, value).good()) {
        std::cout << "Tag " << tag << ": " << value << std::endl;
        return true;
    } else {
        std::cerr << "Tag " << tag << " not found." << std::endl;
        return false;
    }
}

bool readPixelData(const std::string& filename) {
    DcmFileFormat fileformat;
    if (fileformat.loadFile(filename.c_str()).bad()) {
        std::cerr << "Failed to load DICOM file: " << filename << std::endl;
        return false;
    }
    DcmDataset *dataset = fileformat.getDataset();
    DcmElement *pixelData = dataset->getElement(DCM_PixelData);
    if (pixelData) {
        std::cout << "Pixel data read successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Failed to read pixel data." << std::endl;
        return false;
    }
}

bool saveDicom(const std::string& filename, const std::string& outputFilename) {
    DcmFileFormat fileformat;
    if (fileformat.loadFile(filename.c_str()).bad()) {
        std::cerr << "Failed to load DICOM file: " << filename << std::endl;
        return false;
    }
    if (fileformat.saveFile(outputFilename.c_str()).bad()) {
        std::cerr << "Failed to save DICOM file: " << outputFilename << std::endl;
        return false;
    }
    std::cout << "DICOM file saved as " << outputFilename << std::endl;
    return true;
}

bool saveBitmap(const std::string& filename, const std::string& bitmapFilename) {
    DcmFileFormat fileformat;
    if (fileformat.loadFile(filename.c_str()).bad()) {
        std::cerr << "Failed to load DICOM file: " << filename << std::endl;
        return false;
    }
    DcmDataset *dataset = fileformat.getDataset();
    DcmImage image(dataset);
    if (image.getStatus() != EIS_Normal) {
        std::cerr << "Failed to create image from DICOM file." << std::endl;
        return false;
    }
    // Save image to bitmap
    if (image.writeBitmapFile(bitmapFilename.c_str()) != OFTrue) {
        std::cerr << "Failed to save bitmap file: " << bitmapFilename << std::endl;
        return false;
    }
    std::cout << "Bitmap file saved as " << bitmapFilename << std::endl;
    return true;
}
