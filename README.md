# POO-lab
În programul meu am 2 clase: Carte și Librărie. 
* Operatorul += l-am folosit pentru a scumpi o carte cu un anumit pret, iar operatorul -= pentru a ieftini o carte. <br/>
* Pentru operatorii + și – am făcut același lucru. Operatorul == l-am utilizat pentru a verifica dacă 2 cărți sunt identice (am verificat și prețul gândindu-mă că în realitate 2 cărți pot avea aceeași denumire, același autor, dar pot avea prețuri diferite, fiind de la edituri diferite), iar != pentru a verifica dacă 2 cărți au autori diferiți. <br/>
* Pentru clasa Librarie am folosit functia adaugaCarte pentru a adăuga cărți într-o librărie.<br/>
* Funcția actualizareRating modifică rating-ul unei anumite cărți când cineva îi acordă un nou rating. <br/>
* Funcția carteMaiBună cu cei 2 parametri 2 obiecte de tip Carte afișează care dintre cele 2 cărți este mai bună pe baza rating-ului, iar în cazul în care au același rating, le afișează pe ambele. <br/>
* Funcția carteMaiLungă este asemănătoare, doar că afișează care dintre cărți este mai lungă pe baza numărului de pagini.<br/>
* Funcția scumpire are ca parametru o variabilă float și modifică prețul unei cărți în funcție de parametrul p care spune cu ce procent se scumpește cartea.<br/>
* Același lucru îl face și funcția ieftinire, doar că parametrul p indică cu ce procent se ieftinește cartea. Funcția vechime afișează cât de veche este o carte, adică numărul de ani pe care îl are în prezent. <br/>
* Pentru ultima funcție, promoție, am presupus că există o ofertă: dacă cumperi 2 cărți scrise de același autor, poți plăti doar 1, pe cea mai scumpă dintre ele. Funcția verifică dacă 2 cărți au același autor, iar dacă afirmația este falsă returnează 0, iar în caz afirmativ returnează prețul celei mai scumpe dintre cele 2.
