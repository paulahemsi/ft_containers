/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:48:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 17:51:59 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
struct      queue
{
    T*              element;
    struct queue    *next;
	
    queue(void): element(NULL), next(NULL) {}
    queue(T* element): element(element), next(NULL) {}

};

template<typename T>
queue<T> * queue_create_node(T *element)
{
    std::allocator<queue<T> > alloc;

	::queue<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, element);
    return (new_node);
}

template<typename T>
void    queue_push(::queue<T> **queue, ::queue<T> *new_node)
{
    if (!*queue)
    {
        *queue = new_node;
        return;
    }
    ::queue<T> *tmp = *queue;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

template<typename T>
T *queue_pop(::queue<T> **queue)
{
    std::allocator< ::queue<T> >   alloc;
    ::queue<T>                  *tmp = *queue;
    T                           *element = tmp->element;
    
    *queue = (*queue)->next;
    alloc.deallocate(tmp, 1);
    return (element);
}
