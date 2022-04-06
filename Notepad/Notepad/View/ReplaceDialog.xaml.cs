using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Notepad.View
{
    /// <summary>
    /// Interaction logic for ReplaceDialog.xaml
    /// </summary>
    public partial class ReplaceDialog : Window
    {
        public string WhatFind { get; private set; }

        public string Replace { get; private set; }

        public bool ReplaceAll { get; private set; }

        public ReplaceDialog()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            WhatFind = textBox1.Text;
            Replace = textBox.Text;
            DialogResult = true;
            if (checkBox.IsChecked == true)
            {
                ReplaceAll = true;
            }
            else
                ReplaceAll = false;
            this.Close();
        }
    }
}
