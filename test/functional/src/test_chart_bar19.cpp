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

    xlsxwriter::workbook *workbook = new xlsxwriter::workbook("test_chart_bar19.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();
    xlsxwriter::chart     *chart     = workbook->add_chart( xlsxwriter::LXW_CHART_BAR);

    /* For testing, copy the randomly generated axis ids in the target file. */
    chart->axis_id_1 = 66558592;
    chart->axis_id_2 = 66569344;

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

    xlsxwriter::chart_series *series1 = chart->add_series();
    xlsxwriter::chart_series *series2 = chart->add_series();
    xlsxwriter::chart_series *series3 = chart->add_series();

    series1->set_values("Sheet1", 0, 0, 4, 0);
    series2->set_values("Sheet1", 0, 1, 4, 1);
    series3->set_values("Sheet1", 0, 2, 4, 2);

    chart->get_x_axis()->set_name("=Sheet1!$A$2");
    chart->get_y_axis()->set_name("=Sheet1!$A$3");
    chart->title_set_name("=Sheet1!$A$1");

    worksheet->insert_chart(CELL("E9"), chart);

    int result = workbook->close(); return result;
}
