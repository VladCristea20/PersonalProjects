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
    /// Interaction logic for FindDialog.xaml
    /// </summary>
    public partial class FindDialog : Window
    {
        public string SearchedText { get; private set; }

        public bool AllTabs { get; private set; }
        public FindDialog()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            SearchedText = textBox.Text;
            DialogResult = true;
            if((bool)checkBox.IsChecked)
            {
                AllTabs = true;
            }
            else
            {
                AllTabs = false;
            }
            this.Close();
        }
    }
}
