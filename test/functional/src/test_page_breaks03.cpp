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

    xlsxwriter::workbook  *workbook  = new xlsxwriter::workbook("test_page_breaks03.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();
    lxw_row_t breaks[1028] = {0};
    int i;

    for (i = 0; i < 1027; i++)
        breaks[i] = i + 1;

    worksheet->set_paper(9);
    worksheet->set_vertical_dpi(200);

    worksheet_set_h_pagebreaks(worksheet, breaks);

    worksheet->write_string(CELL("A1"), "Foo" , NULL);

    int result = workbook->close(); return result;
}
