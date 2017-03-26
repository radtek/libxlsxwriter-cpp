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

    xlsxwriter::workbook  *workbook  = new xlsxwriter::workbook("test_hyperlink12.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();
    xlsxwriter::format *format = workbook->add_format();

    format->set_underline(xlsxwriter::LXW_UNDERLINE_SINGLE);
    format->set_font_color(xlsxwriter::LXW_COLOR_BLUE);

    worksheet->write_url(CELL("A1"), "mailto:jmcnamara@cpan.org", format);
    worksheet->write_url(CELL("A3"), "ftp://perl.org/", format);

    int result = workbook->close(); return result;
}
