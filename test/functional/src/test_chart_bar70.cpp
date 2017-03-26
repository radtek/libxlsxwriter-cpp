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

    xlsxwriter::workbook *workbook = new xlsxwriter::workbook("test_chart_bar70.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();
    xlsxwriter::chart     *chart     = workbook->add_chart( xlsxwriter::LXW_CHART_BAR);

    /* For testing, copy the randomly generated axis ids in the target file. */
    chart->axis_id_1 = 45925120;
    chart->axis_id_2 = 45927040;

    uint8_t data[5][3] = {
        {1, 2,  3},
        {2, 4,  6},
        {3, 6,  9},
        {4, 8,  12},
        {5, 10, 15}
    };

    int row, col;
    for (row = 0; row < 5; row++)
        for (col = 0; col < 3; col++)
            worksheet->write_number(row, col, data[row][col], NULL);

    worksheet->write_string(CELL("A7"), "Pear" , NULL);

                                chart->add_series(NULL, "=Sheet1!$A$1:$A$5");
    xlsxwriter::LXW_CHART_series *series2 = chart->add_series(NULL, "=Sheet1!$B$1:$B$5");
    xlsxwriter::LXW_CHART_series *series3 = chart->add_series(NULL, "=Sheet1!$C$1:$C$5");

    chart_series_set_name(series2, "Apple");
    chart_series_set_name(series3, "=Sheet1!$A$7");

    worksheet_insert_chart(worksheet, CELL("E9"), chart);

    int result = workbook->close(); return result;
}
