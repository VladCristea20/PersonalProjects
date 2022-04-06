using Microsoft.Win32;
using Notepad.View;
using Notepad.ViewModel;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Input;
using static Notepad.ViewModel.TabControlViewModel;
/// <summary>
/// FileInfo getDirectories / getFiles
/// apel recursiv de load la getDirectories
/// nuGet MicrosoftBehaviourWPF
/// </summary>
namespace Notepad.ViewModel
{
    internal class Commands
    {
        public ICommand NewTabCommand { get; } = new RelayCommand(newTab);
        public ICommand OpenTabCommand { get; } = new RelayCommand(openTab);

        public ICommand SaveAsCommand { get; } = new RelayCommand(saveAs);

        public ICommand SaveCommand { get; } = new RelayCommand(save);

        public ICommand ExitCommand { get; } = new RelayCommand(exit);

        public ICommand AboutCommand { get; } = new RelayCommand(about);

        static void newTab(object e)
        {
            Tabs.Add(new TabViewModel(new Model.TabModel() { Name = $"File {Tabs.Count + 1}",Text="Write something here" }));
        }

        static void openTab(object e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog()
            {
                Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*"
            };

            if(openFileDialog.ShowDialog() == true)
            {
                newTab(e);
                SelectedIndex = Tabs.Count - 1;
                Tabs[SelectedIndex].Name = openFileDialog.FileName;
                Tabs[SelectedIndex].Text = File.ReadAllText(openFileDialog.FileName);
            }

        }

        static void about(object e)
        {
            AboutDialog aboutDialog = new AboutDialog();
            aboutDialog.ShowDialog();
        }

        static void saveAs(object e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "Notepad|*.txt";
            saveFileDialog1.Title = "Save an Text File";
            saveFileDialog1.ShowDialog();

            if(saveFileDialog1.FileName != "")
            {
                Tabs[SelectedIndex].Name = saveFileDialog1.FileName;
                File.WriteAllText(saveFileDialog1.FileName, Tabs[SelectedIndex].Text);
                Tabs[SelectedIndex].Saved = true;
            }
        }

        static void exit(object e)
        {
            if (Tabs[SelectedIndex].Saved == false)
            {
                SaveFile saveFile = new SaveFile();
                if(saveFile.ShowDialog() == true)
                {
                    Tabs.RemoveAt(SelectedIndex);
                }
            }
            else
            {
                Tabs.RemoveAt(SelectedIndex);
            }
        }
        static void save(object e)
        {
            if (Tabs[SelectedIndex].Name.Contains("File"))
            {
                saveAs(e);
            }
            else
            {
                File.WriteAllText(Tabs[SelectedIndex].Name, Tabs[SelectedIndex].Text);
                Tabs[SelectedIndex].Saved = true;
            }
        }

        private RelayCommand findCommand;
        public ICommand FindCommand => findCommand ??= new RelayCommand(Find);

        private void Find(object commandParameter)
        {
            FindDialog findDialog = new FindDialog();
    
            if(findDialog.ShowDialog() == true)
            {
                if(findDialog.AllTabs == false)
                {
                    if (Tabs[SelectedIndex].Text.Contains(findDialog.SearchedText) == true)
                    {
                        MessageBox.Show("Cuvantul " + findDialog.SearchedText + " a fost gasit!");
                    }
                    else
                        MessageBox.Show("Cuvantul " + findDialog.SearchedText + " nu a fost gasit!");
                }
                else
                {
                    bool found = false;
                    for(int index=0;index<Tabs.Count;++index)
                    {
                        if(Tabs[index].Text.Contains(findDialog.SearchedText) == true)
                        {
                            found = true;
                            break;
                        }
                    }
                    if(found == true)
                    {
                        MessageBox.Show("Cuvantul " + findDialog.SearchedText + " a fost gasit!");
                    }
                    else
                    {
                        MessageBox.Show("Cuvantul " + findDialog.SearchedText + " nu a fost gasit!");
                    }
                }
            }
        }

        private RelayCommand replaceCommand;
        public ICommand ReplaceCommand => replaceCommand ??= new RelayCommand(Replace);

        private void Replace(object commandParameter)
        {
            ReplaceDialog replaceDialog = new ReplaceDialog();
            if(replaceDialog.ShowDialog() == true)
            {
                    if(Tabs[SelectedIndex].Text.Contains(replaceDialog.WhatFind) == true)
                    {
                        if (replaceDialog.ReplaceAll == false)
                        {
                            Regex regex = new Regex(Regex.Escape(replaceDialog.WhatFind));
                            Tabs[SelectedIndex].Text = regex.Replace(Tabs[SelectedIndex].Text, replaceDialog.Replace, 1);
                            MessageBox.Show("Cuvantul " + replaceDialog.WhatFind + " s-a inlocuit in prima locatie gasita!");
                        }
                        else if(replaceDialog.ReplaceAll == true)
                        {
                            Regex regex = new Regex(Regex.Escape(replaceDialog.WhatFind));
                            Tabs[SelectedIndex].Text = regex.Replace(Tabs[SelectedIndex].Text, replaceDialog.Replace);
                            MessageBox.Show("Cuvantul " + replaceDialog.WhatFind + " s-a inlocuit peste tot in fisier!");
                        }
                    }
                    else
                        MessageBox.Show("Cuvantul " + replaceDialog.WhatFind + " nu s-a putut inlocui deoarece nu s-a gasit!");
            }
        }
    }
}