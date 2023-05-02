<h1 align="center">NIR-BENCHMARK-GTEST</h1>
На базовой кафедре разрабатывается библиотека IPPFake, заменяющая необходимые функции библиотеки IPP. В связи с постоянными оптимизациями и ускорениями отдельных функций разрабатываемой библиотеки, возникла необходимость написания автоматических тестов и замера времени для каждой функции. В рамках практики поставлена задача написать автоматические тесты и бенчмарки для верной работы этих заменяемых функций.
<h2>Installation</h2>

<h3>Step 1</h3>
Clone a repository.
<br><br>
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/232868616-db79bf2b-0ece-4576-88ab-dd7208e225a2.png" width="900"/>
</div>

---

<h3>Step 2</h3>
Download framework <a href="https://github.com/google/googletest">google test</a> and library <a href="https://github.com/google/benchmark">google benchmark</a>. But if you do not want to install the framework and the library through the git repository into the current working program, then you can install vspkg through it; it is easier to install the necessary libraries for the program to work correctly.
<h3>There will be several steps to install the required libraries if you are using vcpkg</h3>
<h4>Step 2.1</h4>
Install <a href = https://vcpkg.io/en/>vcpkg</a> dependency management from the official website.
<h4>Step 2.2</h4>
In the console change to the directory where vcpkg is installed.<br><br>
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/235762305-73d7448a-557e-4fd1-b498-b4c573916500.png" width="600"/>
</div>
<h4>Step 2.3</h4>
Then enter the command to install the library or framework: <strong>vcpkg install "name library"</strong>
<h4>Step 2.4</h4>
After which you need to go to the directory with <strong>.lib</strong>, <strong>.h</strong> files, links to these repositories need to be transferred to your project. And if there are <strong>.dll</strong> files, then you will need to transfer them to the project for the program to work correctly. See illustrations below.
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/235764426-fa1ec180-92c3-4748-9d27-4dbe8bb0cb17.png" width="950"/><br><br>
</div>
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/235764574-dcc9d939-c7fd-4c72-8298-844e2dd407ff.png" width="950"/><br><br>
</div>
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/235764629-dff7c577-5777-4363-b015-95053917a1c0.png" width="950"/><br><br>
</div>
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/235764657-53f29c8f-261f-44d3-acf3-9128ba3ca716.png" width="950"/><br><br>
</div>
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/101702769/235765385-830b2e29-ebbe-43c4-938d-43cfb11f291e.png" width="600"/><br><br>
</div>

---

<h3>Step 3</h3>
After installing all the necessary files and frameworks and libraries. The program is ready to run and all necessary checks.

---
