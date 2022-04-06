using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using static Notepad.ViewModel.TabControlViewModel;
namespace Notepad.View
{
    /// <summary>
    /// Interaction logic for SaveFile.xaml
    /// </summary>
    public partial class SaveFile : Window
    {
        public SaveFile()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
            if (Tabs[SelectedIndex].Name.Contains("File"))
            {
                SaveFileDialog saveFileDialog1 = new SaveFileDialog();
                saveFileDialog1.Filter = "Notepad|*.txt";
                saveFileDialog1.Title = "Save an Text File";
                saveFileDialog1.ShowDialog();

                if (saveFileDialog1.FileName != "")
                {
                    Tabs[SelectedIndex].Name = saveFileDialog1.FileName;
                    File.WriteAllText(saveFileDialog1.FileName, Tabs[SelectedIndex].Text);
                    Tabs[SelectedIndex].Saved = true;
                }
            }
            else
            {
                File.WriteAllText(Tabs[SelectedIndex].Name, Tabs[SelectedIndex].Text);
                Tabs[SelectedIndex].Saved = true;
            }
            this.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
            this.Close();
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
            this.Close();
        }
    }
}
