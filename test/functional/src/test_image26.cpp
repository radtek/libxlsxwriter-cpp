/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2016, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.hpp"

int main() {

    xlsxwriter::workbook  *workbook  = new xlsxwriter::workbook("test_image26.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();

    worksheet->insert_image(CELL("B2"), "images/black_72.png");
    worksheet->insert_image(CELL("B8"), "images/black_96.png");
    worksheet->insert_image(CELL("B13"), "images/black_150.png");
    worksheet->insert_image(CELL("B17"), "images/black_300.png");

    int result = workbook->close(); return result;
}
