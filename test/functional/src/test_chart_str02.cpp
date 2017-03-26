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

    xlsxwriter::workbook *workbook = new xlsxwriter::workbook("test_chart_str02.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();
    xlsxwriter::chart     *chart     = workbook->add_chart( xlsxwriter::LXW_CHART_SCATTER);

    /* For testing, copy the randomly generated axis ids in the target file. */
    chart->axis_id_1 = 41671680;
    chart->axis_id_2 = 41669376;

    worksheet->write_number(0, 0, 1,     NULL);
    worksheet->write_number(1, 0, 2,     NULL);
    worksheet->write_string(2, 0, "Foo", NULL);
    worksheet->write_number(3, 0, 4,     NULL);
    worksheet->write_number(4, 0, 5,     NULL);

    worksheet->write_number(0, 1, 2,     NULL);
    worksheet->write_number(1, 1, 4,     NULL);
    worksheet->write_string(2, 1, "Bar", NULL);
    worksheet->write_number(3, 1, 8,     NULL);
    worksheet->write_number(4, 1, 10,    NULL);

    worksheet->write_number(0, 2, 3,     NULL);
    worksheet->write_number(1, 2, 6,     NULL);
    worksheet->write_string(2, 2, "Baz", NULL);
    worksheet->write_number(3, 2, 12,    NULL);
    worksheet->write_number(4, 2, 15,    NULL);

    chart->add_series(
         "=Sheet1!$A$1:$A$5",
         "=Sheet1!$B$1:$B$5"
    );

    chart->add_series(
         "=Sheet1!$A$1:$A$5",
         "=Sheet1!$C$1:$C$5"
    );
    worksheet->insert_chart(CELL("E9"), chart);

    int result = workbook->close(); return result;
}
