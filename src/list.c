/*
* MIT License
*
* Copyright (c) 2022 Amber-Sophia Schröck

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "list.h"
#include "string.h"
#include "malloc.h"

typedef struct list_t {
    node_t*	first_entry;
	node_t*	last_entry;
	size_t	num_items;
} list_t;

node_t*   list_get_head(list_t* list) { return list->first_entry; }
node_t*   list_get_end(list_t* list) { return list->last_entry; }
size_t  list_get_size(list_t* list) { return list->num_items; }

void    list_create(list_t* list) {
    memset(list, 0,sizeof(list_t));
}

node_t*     list_add(list_t* list, void* value, size_t size) {
    if(!value) { return NULL; }

    node_t* _new_entry = (node_t*)malloc(sizeof(node_t));
    if(!_new_entry) {  return NULL; }

    // Der neue Eintrag steht an letzter Stelle der Liste.
    // Daher gibt es keinen nächsten Eintrag und der vorherige Eintrag
    // ist der ursprüngliche letzte Listeneintrag.
    _new_entry->prev = list->last_entry;
    if(list->last_entry ) _new_entry->next = _new_entry;
    _new_entry->next = NULL;
    list->last_entry = _new_entry;

    // Wenn die Liste noch ganz leer ist, dann ist dieser Eintrag auch
    // gleichzeitig der erste Eintrag.
    if(!list->first_entry) list->first_entry = _new_entry;

    // Daten kopieren
    memcpy(&_new_entry->value, value, size);
    _new_entry->size = size >= 8 ? size : sizeof(value);

    // Eintragszähler erhöhen
    list->num_items++;

    // Zeiger auf die Listeneintragsstruktur zurückliefern
    return _new_entry;
}

int         list_find(list_t* list, void* value, node_t** pOut) {
    if(!value) return -1;

    // Zuerst den allerersten Listeneintrag testen
    node_t* _current_entry = list->first_entry;
    int _ret = 1;

    while(_current_entry)
    {
        // Die Daten des aktuellen Eintrags mit den angegebenen Daten
        // vergleichen. Falls sie übereinstimmen, ist die Suche beendet.
        if(!memcmp(&_current_entry->value, value, _current_entry->size)) {
            // Falls gewünscht, wird der als Parameter angegebene Doppelzeiger
            // nun auf die Adresse der Listeneintragsstruktur gesetzt.
            if(pOut) *pOut = _current_entry;
            _ret = 0;
            break;
        }

        // Fortschreiten
        _current_entry = _current_entry->next;
    }

    // Es wurde nichts gefunden!
    return _ret;
}

int  list_delete_entry(list_t* list, node_t* entry) {
    if(!entry) { return -1; }

    // Beim Löschen entsteht ein Loch in der Liste, welches nun "gestopft"
    // werden muss. Dabei spielt es eine Rolle, ob der Eintrag an erster
    // oder letzter Stelle oder irgendwo in der Mitte der Liste steht.
    if(entry == list->first_entry && entry == list->last_entry) {
        // Der Eintrag ist der erste und einzige.
        list->first_entry = NULL;
        list->last_entry = NULL;
    } else if(entry == list->first_entry) {
        // Der Eintrag steht an erster Stelle.
        // Der neue erste Eintrag ist nun der Folgende des zu löschenden Eintrags.
        list->first_entry = entry->next;
        list->first_entry->prev = NULL;
    } else if(entry == list->last_entry ) {
        // Der Eintrag steht an letzter Stelle.
        // Der neue letzte Eintrag ist nun der Vorherige des zu löschenden Eintrags.
        list->last_entry  = entry->prev;
        list->last_entry->next = NULL;
    } else {
        // Der Eintrag steht irgendwo in der Mitte.
        // Der vorherige und der folgende Eintrag werden nun verknüpft.
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
    }

    // Der Speicher für sie wurde beim Erstellen eines neuen Eintrags
    // reserviert und kann nun wieder freigegeben werden.
    SAFE_DELETE(entry);

    // Eintragszähler verringern
    list->num_items--;

    return 0;
}

void        list_clear(list_t* list) {
    while(list->first_entry) list_delete_entry(list, list->first_entry);
}

void list_travers(list_t* list, list_callback callback) {
    if(!callback ) return ;

    node_t* _current_entry = list->first_entry;

    while(_current_entry) {
        // Rückruffunktion aufrufen
        if(callback(_current_entry) != 0) break;

        // Fortfahren
        _current_entry = _current_entry->next;
    }
}

void* list_get(node_t* entry) {
    return entry->value;
}
