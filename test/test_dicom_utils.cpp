#include <gtest/gtest.h>
#include "dicom_utils.h"

TEST(DicomUtilsTest, ReadDicomTag) {
    EXPECT_TRUE(readDicomTag("data/sample.dcm", "00100020"));
}

TEST(DicomUtilsTest, ReadPixelData) {
    EXPECT_TRUE(readPixelData("data/sample.dcm"));
}

TEST(DicomUtilsTest, SaveDicom) {
    EXPECT_TRUE(saveDicom("data/sample.dcm", "data/output_test.dcm"));
}

TEST(DicomUtilsTest, SaveBitmap) {
    EXPECT_TRUE(saveBitmap("data/sample.dcm", "data/output_test.bmp"));
}
