## Workflow
1. Requirements update check: [source 1](https://github.com/Ionnier/poo/tree/main) & [source 2](https://github.com/Ionnier/oop-template)
2. Set the tasks to be done & commits & project documentation upgrade
3. Create a new branch & switch on it
4. Solve the tasks
5. Review the tasks following the rules
    - [ ] No compilation errors or warnings (-Wall)
    - [ ] Security: no global variables, all data is private
6. Add unit tests & test the program
7. Add tag to the final commit
8. Push the branch to GitHub
9. Create PR & demand code review
10. Push the branch to the main one

## Tasks
### My tasks
- **Define the basic app functionalities in the project documentation & commit**
- Refactor the prototype plan
- Implement the created structure (spread into multiple tasks) respecting the extras and the given tasks (and abstract the content ideas handling in the prototype plan) ([Third party libraries](https://github.com/fffaraz/awesome-cpp?tab=readme-ov-file))
- Extras: const and &, listă inițializare constructori, pseudo-constructors: definitions and exercises, var(300), diamond inheritance, namespaces, write in multiple files (.h and .cpp files), value initialisation, dynamic memory allocation, resolution operator and external methods, [others](https://github.com/Ionnier/poo/blob/main/labs/L02/README.md)
- Hand in the project (check the indications)
- Project recap and presentation

### Given tasks
- [ ] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
    - pentru o clasă:
        - [ ] constructori de inițializare
        - [ ] constructor supraîncărcat
        - [ ] constructori de copiere
        - [ ] `operator=` de copiere
        - [ ] destructor
        - [ ] `operator<<` pentru afișare (std::ostream)
        - [ ] `operator>>` pentru citire (std::istream)
        - [ ] alt operator supraîncărcat ca funcție membră
        - [ ] alt operator supraîncărcat ca funcție non-membră
    - pentru celelalte clase se va defini doar ce e nevoie
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite (1p):
    - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
    - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] opțiune pentru citirea și afișarea a n obiecte (1p)
- [ ] funcționalitatea creată să folosească metode ale obiectului generic
- [ ] ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
